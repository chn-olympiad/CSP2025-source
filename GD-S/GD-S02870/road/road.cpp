#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,k;
const int maxn=1e6+500;
struct aa{
	int v,w,u; 
}tree[maxn];
int a[10003];
int Check;
bool cmp(aa a,aa b)
{
	return a.w<b.w;
}
int inse(int x)
{
	if(a[x]==x)
	{
		return x;
	}
	a[x]=inse(a[x]);
	return a[x];
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
//	int i=1;
	memset(a,-1,sizeof(a));
	int mm=m*2;
	int i=1;
	for(i;i<=mm;i+=2)
	{
		int x,y;
		cin>>x>>y;
		tree[i].u=x;tree[i].v=y;
		tree[i+1].u=y;tree[i+1].v=x;
		cin>>tree[i].w;
		tree[i+1].w=tree[i].w;
	}
	int nn=n*2;
	int cnt=mm+k*nn;
//	for(int z=1;z<=k;z++)
//	{
//		int x;
//		cin>>x;
//		for(int j=1;j<=nn;j+=2)
//		{
//			int w;
//			cin>>w;
//			cout<<endl<<i<<endl;
//			tree[i+j].u=z;tree[i+j].v=j;
//			tree[i+j].u=j;tree[i+j].v=z;
//			tree[i+j+1].w=tree[i+j].w=w;
//		}
//		i+=nn;
//	}
	sort(tree+1,tree+mm,cmp);
	for(i=1;i<=n;i++)
	{
		a[i]=i;
	}
	for(i=1;i<=mm;i++)
	{
		int x=tree[i].u,y=tree[i].v;
		int xx=inse(x),yy=inse(y);
		if(xx!=yy)
		{
			Check+=tree[i].w;
			a[xx]=yy;
		}
	}
	cout<<Check<<endl;
	return 0;
} 
