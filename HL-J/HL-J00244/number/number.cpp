#include<bits/stdc++.h>
#include<iostream>
using namespace std; 
string s;
int num[1000010],cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			num[cnt]=s[i]-48;
		}
	}
	sort(num,num+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<num[i];
	}
	//^o^
	return 0;
} 
