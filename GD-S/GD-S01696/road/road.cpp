#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int n,m,k;
bool flag;
long long u,v,w,a[10010],tmpu=1;
struct node
{
	long long u,v,w;
}e[N];
long long idx;
//zxscs:
bool cmp(node aa,node bb)
{
	return aa.w<bb.w;
}
long long fa[N];
long long find(long long x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void zxscs()
{
	long long pri=0;
	for(long long i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	sort(e+1,e+1+idx,cmp);
	for(long long i=1;i<=idx;i++)
	{
		long long fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv) continue;
		fa[fu]=fv;
		pri+=e[i].w;
	}
	cout<<pri;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		e[++idx]={u,v,w};
	}
	for(int i=1;i<=k;i++)
	{
		flag=0;
		for(int j=0;j<=n;j++)
		{
			cin>>a[j];
			if(j>0&&a[j]==0&&a[0]==0)
			{
				flag=1;
				tmpu=j;
			}
		}
		if(flag)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==tmpu) continue;
				e[++idx]={tmpu,j,a[j]};
			}
		}
		else
		{
			for(int tu=1;tu<=n;tu++)
			{
				for(int j=1;j<=n;j++)
				{
					if(j==tu) continue;
					e[++idx]={tu,j,a[j]+a[tu]+a[0]};
				}
			}
		}
	}
	zxscs();
	return 0;
}
