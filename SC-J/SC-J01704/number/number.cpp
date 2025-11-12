#include<bits/stdc++.h>
using namespace std;
vector<int> nums;
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s;cin >> s;
	for(char c : s) if(isdigit(c))nums.push_back(c - '0');
	sort(nums.begin(), nums.end() ,greater<int>());
	for(auto x : nums) cout << x;
	fclose(stdin);
	fclose(stdout);
}