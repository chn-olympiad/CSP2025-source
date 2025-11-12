#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[505],c[505],now[505],mul[505];
int n,m;
const int tp=998244353;
int dfs(int depth,int defeat,int win)
{
	if(win+n-depth<=m-1)
	return 0;
	if(win>=m&&depth!=n)
	return mul[n-depth];
	if(depth==n)
	{
		if(win>=m)
		return 1;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(now[i]==1)
		continue;
		now[i]=1;
		if(a[depth+1]==0||defeat>=c[i])
		ans=(ans+dfs(depth+1,defeat+1,win))%tp;
		else
		ans=(ans+dfs(depth+1,defeat,win+1))%tp;
		now[i]=0;
	}
	return ans;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<=n-1;i++)
	a[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++)
	cin>>c[i];
	mul[0]=0;
	mul[1]=1;
	for(int i=2;i<=n;i++)
	mul[i]=mul[i-1]*i%tp;
	if(m==n)
	{
		int tot=0;
		for(int i=1;i<=n;i++)
		if(a[i]*c[i]>=1)
		tot++;
		if(tot==n)
		cout<<mul[n]<<endl;
		else
		cout<<0<<endl;
		return 0;
	}
	cout<<dfs(0,0,0)<<endl;
	return 0;
}
/*
8 3
01111011
0 2 1 2 5 4 3 3
*/
