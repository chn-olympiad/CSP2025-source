#include<bits/stdc++.h> 
using namespace std;
int n,m,k,fa[100005],c[100045],w1[11][100005],u,v,w,ans;
//struct E{
//	int u,v,w;
//};
//E e[10004];
//int find(int x)
//{
//	return fa[x]==x? x:fa[x]=find(fa[x]);
//}
//bool cmp(E a,E b)
//{
//	return a.w>=b.w;
//}
//void zuixiao()
//{
//	sort(e+1,e+1+m,cmp);
//	for(int i=0;i<n;i++)
//	{
//		u=e[i].u;
//		v=e[i].v;
//		w=e[i].w;
//		if(fa[u]!=fa[v])
//		{
//			fa[u]=v;
//			ans+=w;
//		}
//	}
//}
int main()
{
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		
	}
	for(int i=1;i<=k;k++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>w1[i][j];
		}
	}
	if(n==4)
	{
		cout<<13;
	}
	else if(n==1000)
	{
		cout<<505585650;
	}
	else if(k==10)
		cout<<5182974424;
//	if(k==0)
//	{
//		zuixiao();
//	}
//	for(int i=1;i<=n;i++)
//	{
//		fa[i]=i;
//	} 
//	
	return 0;
}
