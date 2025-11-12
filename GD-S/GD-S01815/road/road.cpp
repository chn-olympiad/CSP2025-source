#include<bits/stdc++.h>
#define ll long long
const int N=5e6+10;
const int inf=0x3f3f3f3f;
using namespace std;
int n,m,k,len,num,fin;
int vis[N/100];
int mp[N/100];
ll ans;
struct node
{
	int x,y;
	ll z;
	int num,now;//点 边权 当前所属城市化编号 当前边的编号 
}a[N],minn[N];
struct nodee
{
	int x,ol,z;
}check[N];
int fa[N];
int find(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
bool cmp(node xx,node yy)
{
	return xx.z<yy.z; 
}
void pushup(int id)
{
	if(minn[id*2].z<=minn[id*2+1].z)
	{
		minn[id]=minn[id*2];
	}
	else
	{
		minn[id]=minn[id*2+1];
	}
}
void build(int id,int l,int r)
{
	if(l==r)
	{
		minn[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	pushup(id);
}
void change(int id,int l,int r,int x,int y)
{
	if(l==r)
	{
		minn[id].z+=y;//边权改变
		return; 
	} 
	int mid=(l+r)/2;
	if(x<=mid)
	{
		change(id*2,l,mid,x,y);
	}
	else
	{
		change(id*2+1,mid+1,r,x,y);
	 } 
	 pushup(id);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	for(int i=1;i<N;i++)fa[i]=i;
	scanf("%d%d%d",&n,&m,&k);
	len=m; 
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].z);
		a[i].now=i;
	}
	for(int i=1;i<=k;i++)
	{
		int op;
		ll x;
		scanf("%d",&op);
		mp[i+n]=op;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&x);
			len++;
			a[len]=node{i+n,j,x+op,i,len};
		}
	}
	build(1,1,len);
	for(int i=1;i<=len;i++)
	{
		int fx=find(minn[1].x);
		int fy=find(minn[1].y);
		if(fx!=fy)
		{
			num++;
			check[num]=nodee{fx,fa[fx],minn[1].z};
			fa[fx]=fy;
			ans+=minn[1].z; 
			if(minn[1].x>n and vis[minn[1].x]==0)
			{
				for(int j=m+(minn[1].num-1)*n+1;j<=m+(minn[1].num)*n;j++)//把连着的边全部减掉 
				{
					change(1,1,len,j,-mp[minn[1].x]);
				}
			}
			vis[minn[1].x]++;
			int ma=-inf,mi=inf;
			for(int j=1;j<=n;j++)
			{
				int f=find(j);
				ma=max(ma,f);
				mi=min(mi,f);
			}
			if(ma==mi)break;
		}
		change(1,1,len,minn[1].now,inf);//这条边用不了了 
	}
	fin=find(1);
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

*/
