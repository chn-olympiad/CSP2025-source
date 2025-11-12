#include<bits/stdc++.h>
using namespace std;
string two(int x){
	string s;
	while(x){
		if(x%2==0) s+='0';
		else s+='1';
		x/=2;	
	}
	return s;
}
int  twotoone(string s){
	int n=0;
	int x=2;
	for(int i=0;i<=s.size();i++){
		n+=(s[i]-'0')*x;
		x*=2;
	}
	return n;
}
string yh(string x,string y){
	string s;
	int f=0;
	if(x.size()>y.size()){
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]) s[i]='1';
			else s[i]='0';
		}
	}
	return s;
}
int n,m;
long long a[50200];
long long  k,num=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
		if(a[i]==1) num++;
		}
		cout<<num;
	}else{
		
		for(int i=1;i<=n;i++) if(a[i]==k) num++;
		cout<<num;
	}
	return 0;
}
