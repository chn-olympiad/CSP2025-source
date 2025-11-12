#include<bits/stdc++.h>
using namespace std;
long long t,n,a[111111][4],cnt[4],sum,x,c[111111],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(long long qwer=1;qwer<=t;qwer++)
	{
		cin>>n;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		sum=0;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		for(long long i=1;i<=n;i++)
		{
			long long maxx=a[i][1],maxd=1;
			for(long long j=1;j<=3;j++)
			{
				if(a[i][j]>maxx)
				{
					maxx=a[i][j];
					maxd=j;
				}
			}
			cnt[maxd]++;
			sum+=maxx;
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2)
		{
			cout<<sum<<endl;
			continue;
		}
		x=1;
		if(cnt[1]>n/2)
		{
			x=1;
		}
		if(cnt[2]>n/2)
		{
			x=2;
		}
		if(cnt[3]>n/2)
		{
			x=3;
		}
		ans=0;
		for(long long i=1;i<=n;i++)
		{
			long long maxx=0;
			for(long long j=1;j<=3;j++)
			{
				if(j!=x&&a[i][j]>maxx)
				{
					maxx=a[i][j];
				}
			}
			c[i]=a[i][x]-maxx;
			ans+=maxx;
		}
		sort(c+1,c+n+1);
		for(long long i=n/2+1;i<=n;i++)
		{
			ans+=c[i];
		}
		cout<<ans<<endl;
	}
}
