#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x[11],f[10011],a[11][10001],xx,ans,ans1;
bool d[10011];
struct b
{
	long long x,y,z;
}e[1100001],e1[1100001];
bool cmp(b xx,b yy)
{
	return xx.z<yy.z;
}
int getf(int a)
{
	if(f[a]==a) return a;
	return f[a]=getf(f[a]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int c=1;c<=n;c++)
	{
		f[c]=c;
	}
	for(int c=1;c<=m;c++)
	{
		cin>>e[c].x>>e[c].y>>e[c].z;
	}
	sort(e+1,e+m+1,cmp);
	for(int c=1;c<=m;c++)
	{
		int u=getf(e[c].x),v=getf(e[c].y);
		if(u!=v)
		{
			ans+=e[c].z;
			e[++xx].x=e[c].x;
			e[xx].y=e[c].y;
			e[xx].z=e[c].z;
			f[u]=v;
		}
		if(xx==n-1) break;
	}
	for(int c=1;c<=k;c++)
	{
		cin>>x[c];
		for(int i=1;i<=n;i++)
		{
			cin>>a[c][i];
		}
	}
	for(int c=1;c<(1<<k);c++)
	{
		for(int i=1;i<=n+k;i++)
		{
			f[i]=i;
		}	
		int cnt=n;
		xx=n-1;
		ans1=0;
		for(int i=1;i<=xx;i++)
		{
			e1[i].x=e[i].x;
			e1[i].y=e[i].y;
			e1[i].z=e[i].z;
		}
		for(int i=1;i<=k;i++)
		{
			if(c&(1<<i-1))
			{
				cnt++;
				ans1+=x[i];
				for(int j=1;j<=n;j++)
				{
					e1[++xx].x=i+n;
					e1[xx].y=j;
					e1[xx].z=a[i][j];
				}
			}
		}
		sort(e1+1,e1+xx+1,cmp);
		for(int i=1;i<=xx;i++)
		{
			int u=getf(e1[i].x),v=getf(e1[i].y);
			if(u!=v)
			{
				ans1+=e1[i].z;
				f[u]=v;
			}
			if(xx==cnt-1) break;
		}
		ans=min(ans,ans1);
	}
	cout<<ans;
	return 0;
}
