#include <bits/stdc++.h>
using namespace std;

int n,m;

const int Mod=998244353;

const int M=505;
int s[M];
int a[M];
int arr[M];

int vis[M];
int res[M];

int ans=0;

void dfs(int step)
{
	if (step>n)
	{
		if (res[n]<m) return;
		long long mul=1;
		int cnt=0;
		for (int i=n; i>=1; i--)
		{
			if (vis[i]==1)
			{
				mul=(mul*(arr[res[i]]-cnt))%Mod;
				cnt++;
			}
		}
		ans=(ans+mul)%Mod;
		return;
	}
	res[step]=res[step-1];
	dfs(step+1);
	if (s[step]==1)
	{
		res[step]=res[step-1]+1;
		vis[step]=1;
		dfs(step+1);
	}
	vis[step]=0;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++)
	{
		char c;
		cin>>c;
		s[i]=c-'0';
	}
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
		arr[a[i]]++;
	}
	for (int i=500; i>=0; i--)
	{
		arr[i]+=arr[i+1];
	}
	dfs(1);
	cout<<ans;
	return 0;
}

