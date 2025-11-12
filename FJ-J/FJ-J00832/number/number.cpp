#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<char> nums;
	string line;
	cin>>line;
	for(auto &ec:line){
		if(ec>='0'&&ec<='9'){
			nums.push_back(ec);
		}
	}
	sort(nums.begin(),nums.end(),
		[](char c1,char c2){
			return c1>c2;
		}
	);
	for(auto &ec:nums){
		cout<<ec;
	}
}
