#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e6+5;
struct node{
	int x,y,z;
	bool operator < (const node &a)const {
		return a.z>z;
	}
}a[N],b[N];
int c[15][N];
int fa[N];
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,tot=0;
	cin>>n>>m>>k;
	int cnt=m;
	for(int i=1;i<=m;++i)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		b[i].x=a[i].x,b[i].y=a[i].y,b[i].z=a[i].z;
	}
	for(int i=1;i<=k;++i)
	{
		for(int j=0;j<=n;++j)
		{
			cin>>c[i][j];
		}
		if(c[i][0]==0)
			++tot;
	}
	if(k==0)
	{
		sort(a+1,a+m+1);
		for(int i=1;i<=n;++i)	
			fa[i]=i;
		int sum=0,x,y;
		long long ans=0;
		for(int i=1;i<=m;++i)
		{
			x=find(a[i].x),y=find(a[i].y);
			if(x!=y)
			{
				fa[x]=y;
				ans+=a[i].z;
				++sum;
			}
			if(sum==n-1)
				break;
		}
		cout<<ans;
		return 0;
	}
	if(tot==k)
	{
		for(int i=1;i<=k;++i)
		{
			for(int j=1;j<=n;++j)
			{
				++cnt;
				a[cnt].x=j,a[cnt].y=n+i,a[cnt].z=c[i][j];
			}
		}
		sort(a+1,a+cnt+1);
		for(int i=1;i<=n+k;++i)
			fa[i]=i;
		int x,y,sum=0;
		long long ans=0;
		for(int i=1;i<=cnt;++i)
		{
			x=find(a[i].x),y=find(a[i].y);
			if(x!=y)
			{
				if(x>n)
					fa[x]=y;
				else if(y>n)
					fa[y]=x;
				else
					fa[x]=y,sum++;
				ans+=a[i].z;
				if(sum==n-1)
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	int x,y,sum=0;
	long long ans=0,reans=1e18;
	for(int zt=0;zt<(1<<k);++zt)
	{
		cnt=m;
		x,y,sum=0,ans=0;
		for(int i=1;i<=m;++i)
			a[i].x=b[i].x,a[i].y=b[i].y,a[i].z=b[i].z;
		for(int i=1;i<=k;++i)
		{
			if(((zt>>i-1)&1)==0)continue;
			ans+=c[i][0];
			for(int j=1;j<=n;++j)
			{
				++cnt;
				a[cnt].x=j,a[cnt].y=n+i,a[cnt].z=c[i][j];
			}
		}
		sort(a+1,a+cnt+1);
		for(int i=1;i<=n+k;++i)
			fa[i]=i;
		for(int i=1;i<=cnt;++i)
		{
			x=find(a[i].x),y=find(a[i].y);
			if(x!=y)
			{
				if(x>n)
					fa[x]=y;
				else if(y>n)
					fa[y]=x;
				else
					fa[x]=y,++sum;
				ans+=a[i].z;
			}
			if(sum==n-1)
				break;
		}
		if(sum==n-1)
			reans=min(ans,reans);
	}
	cout<<reans;
	return 0;
}
/*
4 5 0
1 2 3
1 3 4
2 3 2
1 4 2
3 4 5
*/
