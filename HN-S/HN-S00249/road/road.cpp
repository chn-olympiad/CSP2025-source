#include<bits/stdc++.h>
typedef int int32;
#define int long long
using namespace std;
/*
	Author: wbw_121124
	»ÀΩ‹µÿ¡È 
	road.cpp
*/
const int N = 1e4 + 5;
int n,m,k,a[15][N],c[N],fa[N+15],cnt,ans,cntt[15];
struct node{
	int x,y,z;
	bool operator<(const node& u) const
	{
		return z<u.z;
	}
}b[N*100],d[N*110],f[15][N];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y)
		fa[x]=y;
	return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>b[i].x>>b[i].y>>b[i].z;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	int sum=0,tot=0;
	cnt=0;
	for(int j=1;j<=n;j++)
		fa[j]=j;
	for(int j=1;j<=m;j++)
		d[++cnt]=b[j];
	sort(d+1,d+1+m);
	for(int j=1;j<=cnt;j++)
		if(find(d[j].x)!=find(d[j].y))
		{
			sum+=d[j].z;
			unionn(d[j].x,d[j].y);
			tot++;
			b[tot]=d[j];
			if(tot==n-1)
				break;
		}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]<=b[n-1].z)
				f[i][++cntt[i]]={n+i,j,a[i][j]};
	ans=sum;
	for(int i=1;i<(1ll<<k);i++)
	{
		sum=tot=cnt=0;
		for(int j=1;j<=n+k;j++)
			fa[j]=j;
		for(int j=1;j<n;j++)
			d[++cnt]=b[j];
		int tmp=0;
		for(int j=1;j<=k;j++)
			if((i>>(j-1))&1)
			{
				tmp++;
				sum+=c[j];
				for(int l=1;l<=cntt[j];l++)
					d[++cnt]=::f[j][l];
			}
		sort(d+1,d+1+cnt);
		int tot=0;
		for(int j=1;j<=cnt;j++)
			if(find(d[j].x)!=find(d[j].y))
			{
				sum+=d[j].z;
				unionn(d[j].x,d[j].y);
				if(++tot==n+tmp-1)
					break;
			}
		ans=min(ans,sum);
	}
	cout<<ans;
//	cerr<<clock()<<'\n';
	return 0;
}
