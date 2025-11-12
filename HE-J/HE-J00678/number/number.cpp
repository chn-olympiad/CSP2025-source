#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool cmp(char a, char b){
	return a > b;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.ans", "w", stdout);
	
	string input;
	cin >> input;
	
	vector<char> nums(0);
	// get number chars
	for (int i = 0; i<input.size(); i++){
		if (input[i] <= '9' and input[i] >= '0') {
			nums.push_back(input[i]);
		}
	}
	
	sort(nums.begin(), nums.end(), cmp);
	string StrAns = "";
	for (int i = 0; i<nums.size();i++){
		StrAns += nums[i];
	}
	
	cout << StrAns << endl;
	
	return 0;
} 
