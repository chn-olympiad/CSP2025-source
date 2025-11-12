#include <bits/stdc++.h>
using namespace std;

const int M=1e6+25;
const int N=1e4+25;

struct edges
{
	int x,y,z;
} a[M], b[15][N], key[(1<<10)+5][N];

int LG2[(1<<10)+5], sz[(1<<10)+5], fa[N], c[N];
long long sum[(1<<10)+5];

int getfa(int x)
{
	if(x!=fa[x])
		fa[x]=getfa(fa[x]);
	return fa[x];
}

bool merge(int x,int y)
{
	int fax=getfa(x), fay=getfa(y);
	if(fax!=fay)
	{
		fa[fax]=fay;
		return true;
	}
	return false;
}

bool cmp(edges a,edges b)
{
	return a.z<b.z;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
		scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);

	sort(a+1,a+m+1,cmp);

	for(int i=1;i<=n+k;i++)
		fa[i]=i;

	int cnt=0;
	for(int i=1;i<=m;i++)
		if(merge(a[i].x,a[i].y))
			key[0][++cnt]=a[i], sum[0] += a[i].z, sz[0]++;

	for(int i=0;i<k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			b[i][j].x=n+i+1, b[i][j].y=j;
			scanf("%d",&b[i][j].z);
		}

		sort(b[i]+1,b[i]+n+1,cmp);
	}

	for(int i=0;i<k;i++)
		LG2[1<<i]=i;

	for(int S=1;S<1<<k;S++)
	{
		int i=LG2[S&-S], T=S-(1<<i);
		for(int i=1;i<=n+k;i++)
			fa[i]=i;

		int cur1=1, cur2=1, cnt=0;
		while(cur1<=sz[T] || cur2<=n)
		{
			edges Edge;
			if(cur2>n || (cur1<=sz[T] && key[T][cur1].z<=b[i][cur2].z))
				Edge=key[T][cur1++];
			else
				Edge=b[i][cur2++];

			if(merge(Edge.x,Edge.y))
				key[S][++cnt]=Edge, sum[S] += Edge.z, sz[S]++;
		}
	}

	long long ans=sum[0];
	for(int S=0;S<1<<k;S++)
	{
		for(int i=0;i<k;i++)
			if((S>>i)&1)
				sum[S] += c[i];
		ans=min(ans,sum[S]);
	}
	printf("%lld\n",ans);
	return 0;
}