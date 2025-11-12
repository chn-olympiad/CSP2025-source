#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,cnt1,cnt2,cnt3,dp[205][105][105];
struct fun
{
	long long x,y,z,mx,cmx;
}a[100005];
void dfs(long long w,long long ans1,long long ans2,long long ans3,long long nowans)
{
	if (w>n)
	{
		if (ans1*2<=n&&ans2*2<=n&&ans3*2<=n)
		{
			ans=max(ans,nowans);
		}
		return;
	}
	dfs(w+1,ans1+1,ans2,ans3,nowans+a[w].x);
	dfs(w+1,ans1,ans2+1,ans3,nowans+a[w].y);
	dfs(w+1,ans1,ans2,ans3+1,nowans+a[w].z);
	return;
}
bool cmp(fun a,fun b)
{
	return a.mx>b.mx;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].mx=max(max(a[i].x,a[i].y),a[i].z);
		}
		ans=0;
		if (n<=10)
		{
			dfs(0,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}		
		if (n<=200)
		{
			memset(dp,128,sizeof(dp));
			dp[0][0][0]=0;
			for (long long i=1;i<=n;i++)
			{
				for (long long j=0;j*2<=n;j++)
				{
					for (long long k=0;k*2<=n;k++)
					{
						if (j+k>i||(i-j-k)*2>n)
						{
							break;
						}
						if (j&&dp[i-1][j-1][k]>=0)
						{
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i].x);
						}
						if(k&&dp[i-1][j][k-1]>=0)
						{
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i].y);
						}
						if (j+k<i&&dp[i-1][j][k]>=0)
						{
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i].z);
						}
						if (i==n)
						{
							ans=max(ans,dp[i][j][k]);
						}
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		sort(a+1,a+1+n,cmp);
		cnt1=cnt2=cnt3=0;
		for (int i=1;i<=n;i++)
		{
			long long cmx=0;
			if (a[i].mx==a[i].x)
			{
				cmx=max(a[i].y,a[i].z);
			}
			if (a[i].mx==a[i].y)
			{
				cmx=max(a[i].x,a[i].z);
			}
			if (a[i].mx==a[i].z)
			{
				cmx=max(a[i].x,a[i].y);
			}
			a[i].cmx=cmx;
			if (a[i].mx==a[i].x&&cnt1+1<=n/2)
			{
				cnt1++;
				ans+=a[i].mx;
			}
			else if (a[i].mx==a[i].y&&cnt2+1<=n/2)
			{
				cnt2++;
				ans+=a[i].mx;
			}
			else if (a[i].mx==a[i].z&&cnt3+1<=n/2)
			{
				cnt3++;
				ans+=a[i].mx;
			}
			else
			{
				if (a[i].cmx==a[i].x&&cnt1+1<=n/2)
				{
					cnt1++;
					ans+=a[i].cmx;
				}
				else if (a[i].cmx==a[i].y&&cnt2+1<=n/2)
				{
					cnt2++;
					ans+=a[i].cmx;
				}
				else if (a[i].cmx==a[i].z&&cnt3+1<=n/2)
				{
					cnt3++;
					ans+=a[i].cmx;
				}
				else
				{
					if (a[i].x!=a[i].mx&&a[i].x!=cmx) cnt1++,ans+=a[i].x;
					if (a[i].y!=a[i].mx&&a[i].y!=cmx) cnt2++,ans+=a[i].y;
					if (a[i].z!=a[i].mx&&a[i].z!=cmx) cnt3++,ans+=a[i].z;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
