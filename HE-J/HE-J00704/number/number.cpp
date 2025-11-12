#include<bits/stdc++.h>
using namespace std;
string s,ma,p,a;
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=7;i++){
		cin>>s[i];
	}
	for(int i=1;i<=s.size();i++){
		n++;
		if(s[i]>='0'&&s[i]<='9')
			ma[n]+=s[i];
	}
	for(int i=1;i<=ma.size();i++){
		for(int j=1;j<=ma.size();j++){
				a=ma[i];
		a='0';
	}
	for(int i=1;i<=ma.size();i++){
		cout<<p[i];
	}
	return 0;
}} 
