#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,a[505],ans,ans2,y,x,ff[505];
string s;
int f(int n)
{
	int sum=1;
	for(int i=1;i<=n;i++)
	{
		sum=sum*i%mod;
	}
	return sum;
}
void dfs(int idx,int x,int y)
{
	if(idx==n)
	{
		if(x>=m)
		{
			ans=(ans+1)%mod;
		}
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(!ff[i])
		{
			ff[i]=1;
			if(s[idx]=='1'&&a[i]>y)
			{
				dfs(idx+1,x+1,y);
			}
			else
			{
				dfs(idx+1,x,y+1);
			}
			ff[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	if(n<=20)
	{
		dfs(0,0,0);
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==0||s[i]=='0')
			{
				cout<<0;
				return 0;
			}
		}
		cout<<f(n);
		return 0;
	}
	cout<<0;
	return 0;
}
/*
4 1
1011
0 0 2 1
*/

