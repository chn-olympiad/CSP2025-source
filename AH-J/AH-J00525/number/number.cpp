#include<bits/stdc++.h>
using namespace std;
int a[10]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	scanf("std.char",&s);
	for(int i=0;i<=s.length();i++){
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]){
			while(a[i]--)
				printf("%d",i);
		}
	}
	return 0;
}
