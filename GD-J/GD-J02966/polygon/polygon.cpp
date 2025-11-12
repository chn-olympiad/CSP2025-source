#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+100;
long long n,l[MAXN];
int c[100];
bool b[100];
int m;
long long ans;
long long maxl,ansl;
/*
5
1 2 3 4 5
*/ 
bool check()
{
	maxl=-1;
	ansl=0;
	for (int i=1;i<=m;i++)
	{
//		cout<<c[i]<<" ";
		maxl=max(maxl,l[c[i]]);
		ansl+=l[c[i]];
	}
//	cout<<endl;
	return ansl>2*maxl;
}
void dfs(int x)
{
//	cout<<666<<endl;
	if (x>=m)
	{
		if (check())
		{
			ans++;
		}
		return;
	}
	for (int i=c[x]+1;i<=n;i++)
	{
		if (!b[i])
		{
			c[x+1]=i;
			b[i]=true;
			dfs(x+1);
			b[i]=false;
		}
	}
}
long long tt=1;
long long jc(int x)
{
	tt=1;
	for (int i=1;i<=x;i++)
	{
		tt*=i%998244353;
	}
	return tt;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long maxn=0;
	for (int i=1;i<=n;i++)
	{
		cin>>l[i];
		maxn=max(l[i],maxn);	
	}
	if (maxn==1)
	{
		long long as=0;
		long long up=1;
		long long dow=0;
		up=jc(n);
		for (int i=3;i<=n;i++)
		{
			dow=jc(n-i)*jc(i)%998244353;
			as+=(up/dow)%998244353; 
		}
		cout<<as%998244353;
		return 0;
	}
	for (m=3;m<=n;m++)
	{
		dfs(0);
	}
	cout<<ans%998244353;
	return 0;
}
/*
3 1
!n
/!(n-m)!m
4 5
1+4
5 16
1+4+11
6 42
1+4+11+26
7 99

*/
