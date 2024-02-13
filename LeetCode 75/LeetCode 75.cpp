// LeetCode 75.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
class Solution {
public:
    //Q1 LC1768
    string mergeAlternately(string word1, string word2) {
        string word = "";
        word.reserve(word1.length() + word2.length());
        int minLength = min(word1.length(), word2.length());
        for (int i = 0; i < minLength; i++) {
            word += word1[i];
            word += word2[i];
        }
        if (word1.length() < word2.length()) {
            string temp = word2.substr(word1.length());
            word.append(temp);
        }
        else {
            string temp = word1.substr(word2.length());
            word.append(temp);
        }
        return word;
    }
    //Q3 LC1431
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto maxC = max_element(candies.begin(), candies.end());
        vector<bool> result;
        for (int i = 0; i < candies.size(); i++) {
            bool temp;
            if (candies[i] + extraCandies >= *maxC) {
                temp = true;
            }
            else
                temp = false;
            result.push_back(temp);
        }
        return result;
    }

    //Q4 LC605
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int> newF = { 0 };
        newF.insert(newF.end(), flowerbed.begin(), flowerbed.end());
        newF.push_back(0);
        int t = 0;
        for (int i = 1; i <= newF.size() - 1; i++) {
            int temp = newF[i - 1] + newF[i] + newF[i + 1];
            if (temp == 0) {
                t++;
                newF[i] = 1;
            }
            if (t >= n)return true;
        }
        return false;
    }

    //Q5 LC345
    string reverseWords_1(string s) {
        vector<string> temp;
        size_t pos = 0;
        string tempS="";
        string result = "";
        while (pos < s.length())
        {
            if (s[pos] != ' ')
            {
                tempS += s[pos];
            }
            else
            {
                if (tempS != "") {
                    temp.push_back(tempS);
                    tempS = "";
                }
            }
            pos++;
        }
        if (tempS!="")temp.push_back(tempS);
        for (int i = temp.size() - 1; i > 0; i--) {
            result.append(temp[i]);
            result.append(" ");
        }
        result.append(temp[0]);
        return result;
    }
    string reverseWords_2(string s) {
        std::istringstream iss(s);
        std::vector<string> words;
        std::string word;

        // 使用istringstream分割单词，自动处理多个空格问题
        while (iss >> word) {
            words.push_back(word);
        }
        std::reverse(words.begin(), words.end());
        string result;
        if (!words.empty()) {
            result = words[0];
            for (size_t i = 1; i < words.size(); ++i) {
                result += " " + words[i];
            }
        }
        return result;
    }

    //Q6 LC151
    string reverseVowels(string s) {
        vector<char> temp;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'|| s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                temp.push_back(s[i]);
            }
        }
        int t = temp.size()-1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                s[i] = temp[t--];
            }
        }
        return s;
    }

    //Q7 LC238
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>left;
        vector<int>right;
        vector<int>result;
        left.push_back(1);
        right.push_back(1);
        int l = nums.size() - 1;
        for (int i = 0; i < l; i++) {
            left.push_back(left[i] * nums[i]);
            right.push_back(right[i] * nums[l - i]);
        }
        for (int i = 0; i <= l; i++)
        {
            result.push_back(left[i] * right[l - i]);
        }
        return result;
    }


    //Q18 LC1732
    int largestAltitude(vector<int>& gain) {
        int temp = gain[0];
        int max = 0 > temp ? 0 : temp;
        for (int i = 1; i <= gain.size() - 1; i++) {
            temp += gain[i];
            if (temp > max)max = temp;
        }
        return max;
    }
};
int main()
{
    std::cout << "Hello World!\n";
    Solution test;
    vector<int> t = { 1,2,3,4 };
    vector<int> r = test.productExceptSelf(t);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
