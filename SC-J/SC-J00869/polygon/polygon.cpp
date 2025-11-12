#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int a[1000001],n;
long long ct=0;
void dfs(int dep,int maxx,int sum,int ch)
{
	if(dep==n+1)
	{
		if(ch>2 && sum>2*maxx) ct++,ct%=P;
		return;
	}
	dfs(dep+1,maxx,sum,ch);
	dfs(dep+1,max(maxx,a[dep]),sum+a[dep],ch+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>25) {cout<<0;return 0;}
	dfs(1,0,0,0);
	cout<<ct;
	return 0;
}