#include<bits/stdc++.h>
using namespace std;
struct node{
	int fir,sec,thr,mmax;
}a[100010];
bool cmp(node x,node y)
{
	return x.mmax>y.mmax;
}
int dp[210][210][210];
void solve()
{
	int n;
	cin>>n;
	int flagA=1,flagB=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&a[i].fir,&a[i].sec,&a[i].thr);
		a[i].mmax=max(a[i].fir,max(a[i].sec,a[i].thr));
		if(a[i].thr||a[i].sec)flagA=0;
		if(a[i].thr)flagB=0;
	}
	if(flagA)
	{
		int b[100010];
		for(int i=1;i<=n;++i)
		{
			b[i]=a[i].fir;
		}
		sort(b+1,b+n+1);
		int ans=0;
		for(int i=n;i>=n/2+1;--i)
		{
			ans+=b[i];
		}
		cout<<ans<<"\n";
		return;
	}
	if(flagB)
	{
		
	}
	if(n<=200)
	{
		memset(dp,0,sizeof(dp));
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=n/2;j>=0;--j)
			{
				for(int k=n/2;k>=0;--k)
				{
					for(int v=n/2;v>=0;--v)
					{
						if(j)dp[j][k][v]=max(dp[j][k][v],dp[j-1][k][v]+a[i].fir);
						if(k)dp[j][k][v]=max(dp[j][k][v],dp[j][k-1][v]+a[i].sec);
						if(v)dp[j][k][v]=max(dp[j][k][v],dp[j][k][v-1]+a[i].thr);
						ans=max(ans,dp[j][k][v]);
					}
				}
			}
		}
		cout<<ans<<"\n";
		return; 
	}
	sort(a+1,a+n+1,cmp);
	int cnt0=0,cnt1=0,cnt2=0,ans=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i].fir==a[i].mmax)
		{
			if(cnt0<n/2)
			{
				cnt0++;
				ans+=a[i].fir;	
			}
			else
			{
				ans+=max(a[i].sec,a[i].thr);
			}
		}
		else if(a[i].sec==a[i].mmax)
		{
			if(cnt1<n/2)
			{
				cnt1++;
				ans+=a[i].sec;
			}
			else
			{
				ans+=max(a[i].fir,a[i].thr);
			}
		}
		else
		{
			if(cnt2<n/2)
			{
				cnt2++;
				ans+=a[i].thr;		
			}
			else
			{
				ans+=max(a[i].sec,a[i].fir);
			}
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int tt;
	cin>>tt;
	while(tt--)
	{
		solve();
	}
}
