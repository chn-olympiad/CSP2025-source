#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	
	string s;// 字符串 s 仅含小写英文字母及数字，且包含至少一个1∼9中的数字
	cin >> s;
	
	vector<int> nums; // s 中数
	for(char c : s)
		if(isdigit(c))
			nums.push_back(c - '0'); // 获取 s 中的任意多个数字
	
	sort(nums.begin(), nums.end(), greater<int>());	// 按单调下降拼成一个正整数.(可选 s 中同数字,每个数字只能用一次)
	
	// 求正整数的最大值
	if(nums.front() == 0) printf("0"); // 注意最大值为0时
	else for(int dig : nums) printf("%d", dig);
	return 0;
}