#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,sum;
long long p[10005],a[10005][10005],s[10005],t[10005];
bool w[10005];
struct ST{
	long long x,y,c;
}r[10005];
bool cmp(ST a,ST b)
{
	return a.c<b.c;
}
int main()
{
	ios::sync_with_stdio(),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>r[i].x>>r[i].y>>r[i].c;
	}
	for(long long i=1;i<=k;i++)
	{
		cin>>p[i];
		for(long long j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	sort(r+1,r+n+1,cmp);
	if(k==0)
	{
		for(long long i=1;i<=n;i++)
		{
			if(w[r[i].x]>0&&w[r[i].y]>0)
			{
				continue;
			}
			else
			{
				ans+=r[i].c;
				w[r[i].x]++;
				w[r[i].y]++;
			}
			bool f=0;
			for(long long j=1;j<=n;j++)
			{
				if(w[j]==0)
				{
					f=1;
					break;
				}
			}
			if(!f)
			{
				cout<<ans;
				return 0;
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		if(w[r[i].x]>0&&w[r[i].y]>0)
		{
			continue;
			bool f=0;
			for(long long j=1;j<=n;j++)
			{
				if(w[j]==0)
				{
					f=1;
					break;
				}
			}
			if(!f)
			{
				break;
			}
		}
		else
		{
			long long minn=INT_MAX;
			for(long long j=1;j<=k;j++)
			{
				if(w[r[i].x]>0&&w[r[i].y]==0)
					minn=min(minn,a[j][r[i].y]+p[j]);
				else if(w[r[i].x]==0&&w[r[i].y]==0)
					minn=min(minn,a[j][r[i].x]+a[j][r[i].y]+p[j]);
				else if(w[r[i].x]==0&&w[r[i].y]>0)
					minn=min(minn,a[j][r[i].x]+p[j]);
			}
			ans+=min(r[i].c,minn);
			w[r[i].x]++;
			w[r[i].y]++;
		}
		bool f=0;
		for(long long j=1;j<=n;j++)
		{
			if(w[j]==0)
			{
				f=1;
				break;
			}
		}
		if(!f)
		{
			break;
		}
	}
	cout<<ans;
	return 0;
} 

