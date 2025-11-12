#include<bits/stdc++.h>
using namespace std;
string s,a;
int b[1000005];
int tmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(int(s[i]-'0')>=0&&int(s[i]-'0')<=9){
			a+=s[i];
		}
	}
	for(int i=0;i<a.size();i++){
		b[i]=int(a[i]-'0');
	}
	int n=a.size();
	sort(b,b+n,tmp);
	for(int i=0;i<a.size();i++){
		cout<<b[i];
	}
	return 0;
}
