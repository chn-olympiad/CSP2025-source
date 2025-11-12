#include <bits/stdc++.h>
using namespace std;

const int N=5010,MOD=998244353;
int a[N],C[N][N];
int vis[N];
int ans;
int n;
bool check()
{
	int maxn=0,sum=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		maxn=max(maxn,(vis[i]*a[i]));
		sum+=vis[i]*a[i];
		cnt+=vis[i];
	}
	return ((sum>maxn*2)&&cnt>=3);
}
void dfs(int step)
{
	if(step>n)
	{
		if(check()) ans++;
		return ;
	}
	vis[step]=1;
	dfs(step+1);
	vis[step]=0;
	dfs(step+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=5000;i++) C[i][1]=1;
	for(int i=1;i<=5000;i++) C[i][i]=1;
	for(int i=1;i<=5000;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i==1||i==j) continue;
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
		}
	}
//	for(int i=1;i<=5;i++)
//	{
//		for(int j=1;j<=i;j++) cout<<C[i][j]<<" ";
//		cout<<endl;
//	}
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag)
	{
		int ans=0;
		for(int i=3;i<=n;i++) ans=(ans+C[n+1][i+1])%MOD;
		cout<<ans<<endl;
	}
	else
	{
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
*/