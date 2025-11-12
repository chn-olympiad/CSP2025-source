#include<bits/stdc++.h>
using namespace std;
bool s[510];
int c[510],sgms,sgm0;
int n,m;
bool b[510];
long long jc(int x)
{
	long long res=1;
	for(int i=1;i<=x;i++)res=(res*i)%998244353;
	return res;
}
long long dfs(int fail,int pass)
{
	if(n-fail<m)return 0;
	if(pass==m)return jc(n-fail-pass);
	long long res=0;
	for(int i=1;i<=n;i++)if(!b[i])
	{
		b[i]=true;
		if(c[i]>fail&&s[fail+pass+1])res+=dfs(fail,pass+1);
		else res+=dfs(fail+1,pass);
		b[i]=false;
	}
	return res%998224353;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		if(c=='1')s[i]=true,sgms++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)sgm0++;
	}
	if(m>sgms)
	{
		cout<<0;
		return 0;
	}
	if(m==n)
	{
		if(sgms<n||sgm0>0)cout<<0;
		else cout<<jc(n);
		return 0;
	}
	cout<<dfs(0,0);
	return 0;
}
