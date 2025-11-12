#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int> stk(10);
	string s;
	cin>>s;
	int k=s.size();
	for(int i=0;i<k;i++){
		if(s[i]>='0'&&s[i]<='9'){
			stk[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		string tmp(200,i+'0');
		for(int j=0;j<stk[i]/200;j++){
			cout<<tmp;
		}
		for(int j=0;j<stk[i]%200;j++){
			printf("%d",i);
		}
	}
	return 0;
}

