#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int>num(10,0);
	string s;
	cin>>s;
	for(int i = 0;i<s.size();i++){
		if(s[i]>='1' && s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i = 9;i>=1;i--){
		for(int j = 0;j<num[i];j++){
			cout<<i;
		}
	}
	return 0;
}
