#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n;int ans=0;
int a[100005][4];
int dp[2][100005][4];
int vis[4];
void dfs(int id,int sum)
{
	if(id==n+1){ans=max(ans,sum);return ;}
	if(vis[1]<n/2)
	{
		vis[1]++;
		dfs(id+1,sum+a[id][1]);
		vis[1]--;
	}
	if(vis[2]<n/2)
	{
		vis[2]++;
		dfs(id+1,sum+a[id][2]);
		vis[2]--;
	}
	if(vis[3]<n/2)
	{
		vis[3]++;
		dfs(id+1,sum+a[id][3]);
		vis[3]--;
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		bool flag=1;ans=0;
		vector<int> v;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			v.push_back(a[i][1]);
			if(a[i][2]!=0 || a[i][3]!=0)flag=0;
		}
		if(flag==1)
		{
			sort(v.begin(),v.end());n/=2;
			for(int i=v.size()-1;i>=0 && n>0;i--)ans+=v[i],n--;
			cout<<ans<<"\n";
			continue;
		}
		if(n<=30)
		{
			memset(vis,0,sizeof vis);
			ans=0;
			dfs(1,0);
			cout<<ans<<"\n";
			continue;
		}
		memset(dp,0,sizeof dp);
		int f=1;
		for(int i=1;i<=n;i++)
		{
			for(int v=n/2-1;v>=0;v--)
			{
				dp[f][v+1][1]=max({dp[f^1][v][1]+a[i][1],dp[f^1][n/2][2]+a[i][1],dp[f^1][n/2][3]+a[i][1]});
				dp[f][v+1][2]=max({dp[f^1][n/2][1]+a[i][2],dp[f^1][v][2]+a[i][2],dp[f^1][n/2][3]+a[i][2]});
				dp[f][v+1][3]=max({dp[f^1][n/2][1]+a[i][3],dp[f^1][n/2][2]+a[i][3],dp[f^1][v][3]+a[i][3]});
			}
			f^=1;
		}
		cout<<max({dp[n%2][n/2][1],dp[n%2][n/2][2],dp[n%2][n/2][3]})<<"\n";
	}
	return 0;
}
