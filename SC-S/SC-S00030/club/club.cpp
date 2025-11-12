#include<bits/stdc++.h>
#define maxn 210
#define qwq return
using namespace std;
int t,n;
int a[maxn][4];
int cnt[4];
int ans=0;
void dfs(int x,int w)
{
	if(x==n+1)
	{
		ans=max(ans,w);
		qwq;
	}
	for(int i=1;i<=3;i++)
	{
		if(cnt[i]+1>(n/2))continue;
		cnt[i]++;
		w+=a[x][i];
		dfs(x+1,w);
		w-=a[x][i];
		cnt[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t)
	{
		t--;
		cin>>n;
		if(n<=30)
		{
			ans=0;
			memset(cnt,0,sizeof(cnt));
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)cin>>a[i][j];
			}
			dfs(1,0);
			cout<<ans<<endl;
		}
		else
		{
			long long z[maxn];
			for(int i=1;i<=n;i++)cin>>z[i];
			sort(z+1,z+n+1);
			long long sum=0;
			for(int i=n;i>(n/2);i--)sum+=z[i];
			cout<<sum;
		}
	}
	qwq 0;
}