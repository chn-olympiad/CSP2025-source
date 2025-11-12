#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5,N=1e4+5;
int a[15][N],c[15];
long long sum=0;
struct st
{
	int u,v,w;
}s[M];
bool cmp(st x,st y)
{
	if(x.u<y.u)return 1;
	else if(x.u==y.u)return x.v<y.v;
	else return 0;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&s[i].u,&s[i].v,&s[i].w);
	}
	sort(s+1,s+1+m,cmp);
	for(int i=1;i<m;i++)
	{
		if(s[i].u==s[i+1].v)
		{
			s[i].u=(s[i].w+s[i+1].w)/2;
			s[i].v=(s[i].w+s[i+1].w)/2;
		}
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int mi=INT_MAX,num=0;
		for(int j=1;j<=k;j++)
		{
			if(mi>c[j]+a[j][s[i].u]+a[j][s[i].v])
			{
				mi=c[j]+a[j][s[i].u]+a[j][s[i].v];
				num=j;
			}
		}
		if(mi<=s[i].w)
		{
			sum+=mi;
			a[num][s[i].u]=0;
			a[num][s[i].v]=0;
			c[num]=0;
		}
		else
		{
			sum+=s[i].w;
		}
	}
	cout<<sum;
	return 0;	
}
