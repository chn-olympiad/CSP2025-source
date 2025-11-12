#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int M = 1000005;
string s;
int nums[M];
bool cmp(int x,int y){
	if(x>y) return true;
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int j = 0;
	for(int i = 0;i<s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			nums[j++] = s[i]-'0';
		}
	}
	sort(nums,nums+j+1,cmp);
	for(int i = 0;i<j;i++){
		cout<<nums[i];
	}
	return 0;
}
