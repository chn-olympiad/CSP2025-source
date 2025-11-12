#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int w[3000005][3],a[20005],cnt1;
int e[3000005][3];
int e2[1000005][3];
void in(int x,int y,int z)
{
	cnt1++;
	w[cnt1][0]=y;
	w[cnt1][1]=z;
	w[cnt1][2]=a[x];
	a[x]=cnt1;
}
void in2(int x,int y,int z)
{
	m++;
	e[m][0]=x;
	e[m][1]=y;
	e[m][2]=z;
}
void qsort(int l,int r)
{
	if(l>=r) return;
	int i=l,j=r,mid=e[rand()%(r-l+1)+l][2];
	while(i<=j)
	{
		while(e[i][2]<mid) i++;
		while(e[j][2]>mid) j--;
		if(i<=j)
		{
			swap(e[i][0],e[j][0]);
			swap(e[i][1],e[j][1]);
			swap(e[i][2],e[j][2]);
			i++; j--;
		}
	}
	qsort(i,r); qsort(l,j);
}
int f[20005];
int find(int x)
{
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
long long ans=INT_MAX,cnt=0;
void mst()
{
	qsort(1,m);
	for(int i=1;i<=n;i++) f[i]=i;
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		if(find(e[i][0])==find(e[i][1])) continue;
		sum++;
		f[find(e[i][0])]=find(e[i][1]);
		cnt+=e[i][2];
		if(sum==n-1) break;
	}
	ans=min(ans,cnt);
}
int p[25],v[25][10005];
bool b[25];
void dg(int x)
{
	if(x==k)
	{
		int top=m; cnt=0;
		for(int i=1;i<=k;i++) cnt+=b[i]*p[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int minn=INT_MAX;
				for(int l=1;l<=k;l++)
				{
					if(b[l]==0) continue;
					minn=min(minn,v[l][i]+v[l][j]);
				}
				in2(i,j,minn);
			}
		}
		mst(); m=0; 
		for(int i=1;i<=top;i++)
		{
			in2(e2[i][0],e2[i][1],e2[i][2]);
		}
		return;
	}
	b[x+1]=1; dg(x+1);
	b[x+1]=0; dg(x+1);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&e[i][0],&e[i][1],&e[i][2]);
		in(e[i][0],e[i][1],e[i][2]); in(e[i][1],e[i][0],e[i][2]);
		e2[i][0]=e[i][0]; e2[i][1]=e[i][1]; e2[i][2]=e[i][2];
	}
	bool flaga=0,flagg=1;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&p[i]);
		if(p[i]>0) flaga=1;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&v[i][j]);
			if(v[i][j]>0) flaga=1;
		}
		if(flaga==0) flagg=0;
	}
	if(flagg==0)
	{
		printf("0");
		return 0;
	}
	if(k==0)
	{
		mst();
		printf("%lld",ans);
		return 0;
	}
	dg(0);
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4



4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 0 0 0
0 0 0 0 0
*/
