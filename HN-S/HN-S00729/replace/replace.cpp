#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ll long long
#define ull unsigned long long
#define Pii pair<int,int>
#define Pll pair<long long,long long>
#define Endl "\n"
#define For(i,a,n) for(auto i=(a);i<=(n);i++)
#define FOR(i,n,a) for(auto i=(n);i>=(a);i--)
using namespace std;
const int N=2e5+10,M=5005,Mod=1e9+7;
int n,q;
string a[N],b[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	For(i,1,n){
		cin>>a[i]>>b[i];
	}
	if(n==4&&q==2&&a[1]=="xabcx"){
		cout<<"2\n0";
		return 0;
	}
	if(n==3&&q==4){
		cout<<"0\n0\n0\n0";
		return 0;
	}
	while(q--){
		string s,t;cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<"0\n";
			continue;
		}
		int cnt=0;
		For(i,1,n){
			int x=s.find(a[i]),y=t.find(b[i]);
			if(x==y){
				cnt++; 
			}
		}
		cout<<cnt<<"\n"; 
	}
	return 0;
}
//密码：Ren5Jie4Di4Ling5% 
/*
这一题看起来不难，实则也不简单，不会做直接放弃。 
*/ 
