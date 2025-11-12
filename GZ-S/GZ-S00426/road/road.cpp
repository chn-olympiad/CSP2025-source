//GZ-S00426 遵义市第四中学 赵振宇
#include<bits/stdc++.h>
using namespace std;
struct node
{
	unsigned long long from,to,w;
	unsigned long long v,w1;
}mp[20000005];
unsigned long long n,m,k,vill;
unsigned long long fa[10201];
unsigned long long u,v,w;
unsigned long long vis[11];
unsigned long long tmp;
unsigned long long ans;
bool flag=true;
unsigned long long find(unsigned long long x)
{
	while(fa[x]!=x)
		x=fa[x];
	return fa[x];
}
bool cmp1(node a,node b)
{
	return a.w+a.w1<b.w+b.w1;
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
bool judge()
{
	for(int i=1;i<n;i++)
	{
		if(find(i)!=find(i+1))
			return false;
	}
	return true;
}
void kruskal()
{
	sort(mp+1,mp+m+n*k+1,cmp);
	for(int i=1;i<=m+n*k;i++)
	{
		unsigned long long ff=find(mp[i].from);
		unsigned long long ft=find(mp[i].to);
		unsigned long long ww=mp[i].w;
		unsigned long long vv=0;
		if(mp[i].w1!=0)
			vv=mp[i].v;
		if(ff!=ft)
		{
			fa[ft]=ff;
			ans+=ww;
		}
		if(judge())
			return ;
	}
}
void kruskal11()
{
	sort(mp+1,mp+m+n*k+1,cmp1);
	for(int i=1;i<=m+n*k;i++)
	{
		unsigned long long ff=find(mp[i].from);
		unsigned long long ft=find(mp[i].to);
		unsigned long long ww=mp[i].w+mp[i].w1;
		unsigned long long vv=0;
		if(mp[i].w1!=0)
			vv=mp[i].v;
		if(ff!=ft)
		{
			fa[ft]=ff;
			ans+=ww;
			if(vis[vv]==0)
			{
				vis[vv]=1;
				for(int j=1;j<=m+n*k;j++)
				{
					if(mp[j].v==vv)
						mp[j].w1=0;
				}
				sort(mp+1,mp+m+n*k+1,cmp1);
				i=0;
			}
		}
		if(judge())
			return ;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	vis[0]=1;
	for(int i=1;i<=n+k+1;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>mp[i].from>>mp[i].to>>mp[i].w;
		mp[i].v=0;
		mp[i].w1=0;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>tmp;
			if(j==1)
			{
				vill=tmp;
				if(vill!=0)
					flag=false;
			}	
			else
			{
				mp[m+i*(j-1)].from=n+i;
				mp[m+i*(j-1)].to=j-1;
				mp[m+i*(j-1)].w=tmp;
				mp[m+i*(j-1)].v=i;
				mp[m+i*(j-1)].w1=vill;
			}
		}
	}
	if(flag)
	{
		kruskal();
		cout<<ans;
	}	
	else
	{
		kruskal11();
		cout<<ans;
	}
	return 0;
}

