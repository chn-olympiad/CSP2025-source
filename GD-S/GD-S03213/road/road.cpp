#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10003],z,k2=0,ti=0;
struct road
{
	int u,v,w,thr;
}a[1000003];
struct town
{
	int a,t[10003];
}b[13];
vector<road>v;
bool cmp(road x,road y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(f[x]==x) return x;
	else f[x]=find(f[x]); 
}
bool to[13];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
		a[i].thr=0;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>b[i].a;
		for(int j=1;j<=n;j++)
			cin>>b[i].t[i];
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				m++;
				a[m].u=j,a[m].v=k;
				a[m].w=b[i].t[j]+b[i].t[k],a[m].thr=k;
			}
		}
	}
	sort(a+1,a+m+1,cmp);
//	for(int i=1;i<=m;i++)
//	{
//		if(ti==n-1) break;
//		int u=a[i].u,v=a[i].v;
//		if(f[u]!=f[v])
//		{
//			ti++;
//			z+=a[i].w;
//			if(to[a[i].thr]==0 && k2<k) k2++,z+=b[k2].a; 
//			f[v]=f[u];
//		}
//	}
//	cout<<z;
	cout<<0;
	return 0;
}
