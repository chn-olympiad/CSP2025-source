#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][5],t,cnt[5];
bool vis[N][5];
long long ans=0;
void special()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[i][1]<a[j][1]) swap(a[i][1],a[j][1]);
		}
	}
	for(int i=1;i<=n/2;i++)
	{
		ans+=a[i][1];
	} 
}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i][2]!=0||a[i][3]!=0) return 1;
	}
	return 0;
}
long long sumn()
{
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(vis[i][j]) sum+=a[i][j];
		}
	}
	return sum;
}
void dfs(int k)
{
	if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2) return ;
	if(k>n) 
	{
		ans=max(sumn(),ans);
		return ;
	}
	
	for(int i=1;i<=3;i++)
	{
		vis[k][i]=1;
		cnt[i]++;
		dfs(k+1);
		vis[k][i]=0;
		cnt[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		memset(vis,0,sizeof(vis));
		ans=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		if(check()==0) special();
		else dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
} 
