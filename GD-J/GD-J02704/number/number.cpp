#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	bool p=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			if(x!=0)p=0;
			a[x]++;
		}
	}
	if(p){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
/*
有玩原神的吗，我是萌新，求搭子，周末上线，冒险等级50级
UID：307834949 
我推芙芙
Furina is so cute!!!
*/ 
