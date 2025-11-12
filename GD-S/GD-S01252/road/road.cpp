#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxm=1e6+5;
int n,m,k;
int c[15][maxn];
struct ss
{
	int x,y,w;
}aa[2*maxm];
bool cmp(ss A,ss B)
{
	return A.w<B.w;
}
int f[maxn];
int findd(int x)
{
	if(f[x]==x)return x;
	f[x]=findd(f[x]);
	return f[x];
}
int x[maxm],y[maxm],w[maxm];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>x[i]>>y[i]>>w[i];
	for(int i=1;i<=k;i++)for(int j=0;j<=n;j++)cin>>c[i][j];
	long long T=((1<<k)*m*20);
	if(T>4e7)
	{
		int M=m,N=n;
		long long s=0;
		for(int i=1;i<=k;i++)
		{
			N++;
			for(int j=1;j<=n;j++)
			{
				M++;
				aa[M].w=c[i][j],aa[M].x=i+n,aa[M].y=j;
			}
		}
		for(int i=1;i<=N;i++)f[i]=i;
		sort(aa+1,aa+1+M,cmp);
		int o=0;
		for(int i=1;i<=M;i++)
		{
			int u=aa[i].x,v=aa[i].y,val=aa[i].w;
			if(findd(u)==findd(v))continue;
			s+=val;
//			cout<<val<<' ';
			f[f[u]]=v;
			o++;
		}
		cout<<s;
		return 0;
	}
	int t=(1<<k)-1;
	long long z=1e17;
	for(;t>=0;t--)
	{
		int M=m,N=n;
		long long s=0;
		for(int i=1;i<=m;i++)aa[i].x=x[i],aa[i].y=y[i],aa[i].w=w[i];
		for(int i=1;i<=k;i++)
		{
			if((t>>(i-1))&1)
			{
				N++;
				s+=c[i][0];
				for(int j=1;j<=n;j++)
				{
					M++;
					aa[M].w=c[i][j],aa[M].x=N,aa[M].y=j;
				}
			}
		}
		for(int i=1;i<=N;i++)f[i]=i;
		sort(aa+1,aa+1+M,cmp);
		int o=0;
		for(int i=1;i<=M;i++)
		{
			int u=aa[i].x,v=aa[i].y,val=aa[i].w;
			if(findd(u)==findd(v))continue;
			s+=val;
			f[findd(u)]=findd(v);
			o++;
//			if(o==N-1)break;
		}
		if(o==N-1)z=min(z,s);
	}
	cout<<z;
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

*/
