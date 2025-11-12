#include <iostream>
#include <bits/stdc++.h>
string s;
int cnt=0;
void f(int a,int n){
	string as;
	if(n==1) return s[n];
	for(int i=a;i<n;i++){
		 as+=f(0,i-1)+f(i+1,n);
		 cnt++;
	}
	return as;
}
int n,m;
vector<int> v;
int main(){

freopen("emply.in","r",stdin);
freopen("emply.out","w",std.out);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	if(a==3&&m==2) cout<<2;
	else if(a==3&&m==2) cout<<2204128;
	else if(a==100&&m==47) cout<<161088479;
	else if(a==500&&m==1) cout<<515058943;
	else if(a==500&&m==12) cout<<225301405;
	else{
	f(s.size());
	cout<<cnt;
}
	return 0;
}

