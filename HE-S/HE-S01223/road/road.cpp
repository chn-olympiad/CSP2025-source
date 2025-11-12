#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,k;
struct nd{int u;int v;int w;}a[2000005];
int az=0;
bool cmp(nd a,nd b)
{
	return a.w<b.w;
}
int f[20005];
int find(int s)
{
	if(f[s]==s)return s;
	return f[s]=find(f[s]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		az++;
		a[az].u=u;
		a[az].v=v;
		a[az].w=w;
	}
	for(int i=1;i<=k;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=1;j<=n;j++)
		{
			int w;
			scanf("%d",&w);
			az++;
			a[az].u=n+i;
			a[az].v=j;
			a[az].w=w;
		}
	}
	for(int i=1;i<=n+k;i++)
	{
		f[i]=i;
	}
	sort(a+1,a+az+1,cmp);
	int cnt=0;
	long long ans=0;
	for(int i=1;i<=az;i++)
	{
		int f1=find(a[i].u);
		int f2=find(a[i].v);
		if(f1!=f2)
		{
			f[f1]=f2;
			ans+=a[i].w;
			cnt++;
		}
		if(cnt==n+k)break;


	}
	cout<<ans;
	return 0;
}
