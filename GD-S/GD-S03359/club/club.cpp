#include<bits/stdc++.h>

using namespace std;

int t,n;
struct peo
{
	int a;
	int b;
	int c;
};
peo a[500005];
int ans;
int dp[500005][3];

void dfs(int t,int sum,int ta,int tb,int tc)
{
	if(ta>(n/2)||tb>(n/2)||tc>(n/2))
	{
		
		return;
	}
	if(t==n)
	{
		//cout<<"here";
		ans=max(ans,sum);
		return;
	}
	dfs(t+1,sum+a[t+1].a,ta+1,tb,tc);
	dfs(t+1,sum+a[t+1].b,ta,tb+1,tc);
	dfs(t+1,sum+a[t+1].c,ta,tb,tc+1);
}

bool cmp(peo a,peo b)
{
	if(a.a!=b.a)
	{
		return a.a>b.a;
	}
	else
	{
		return a.b>b.b;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ii=0;ii<t;ii++)
	{
		cin>>n;
		ans=0;
		int flg=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].c!=0||a[i].b!=0)
			{
				flg=1;
			}
		}
		if(n<=30)
		{
			
			dfs(0,0,0,0,0);
			cout<<ans<<'\n';
		}
		else if(!flg)
		{
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=(n/2);i++)
			{
				ans+=a[i].a;
			}
			cout<<ans<<'\n';
		}
		else
		{
			dp[0][0]=0;
			dp[0][1]=0;
			dp[0][2]=0;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++)
			{
				dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+a[i].a;
				dp[i][1]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+a[i].b;
				dp[i][2]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+a[i].c;
			}
			cout<<max(max(dp[n][0],dp[n][1]),dp[n][2])<<'\n';
		}
	}
	
} 
