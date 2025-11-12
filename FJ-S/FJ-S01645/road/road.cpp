#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int used[15],b[15];
int fa[11451];
int find(int x)
{
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	return x;
}
struct edge{int u,v,w,coun;}a[1114514];
bool cmp(edge x,edge y){return x.w<y.w;}
bool check()
{
	for(int i=2;i<=n;i++) if(find(1)!=find(i)) return 0;
	return 1;
}
void merge(int u,int v)
{
	u=find(u),v=find(v);
	fa[u]=v;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w,a[i].coun=-1;
	int idx=m+1;
	if(k!=0)
	{
		for(int i=1;i<=k;i++)
		{
			cin>>b[i];
			int cij[11451]={0};
			for(int j=1;j<=n;j++) cin>>cij[j];
			for(int u=1;u<=n;u++)
			{
				for(int v=1;v<=n;v++)
				{
					if(u==v) continue;
					a[idx].coun=i,a[idx].u=u,a[idx].v=v,a[idx++].w=cij[u]+cij[v]+b[i];
				}
			}
		}
	}
	sort(a+1,a+m+idx+1,cmp);
	int ans=0,i=1;
	while(!check())
	{
		int u=a[i].u,v=a[i].v,w=a[i].w,c=a[i].coun;
		if(find(u)!=find(v)) 
		{
			ans+=w,merge(u,v);
			if(c!=-1) 
			{
				if(used[c]>2) ans-=2*b[c];
				if(used[c]==2) ans-=b[c];
				used[c]++;
			}
		}
		i++;
	}
	cout<<ans;
	return 0;
}
//I love CCF
//rp++;
/*
	你说堵桥是犯罪 想让我知难而退
	浮木不需要原配 只要瓦里的姐姐
	堵撤离的每一队 极限的飞升一接
	全家福就代表 全世界
	亲爱的 是七夕 鹊桥堵你
	我们战线统一
	亲爱的 别撤离 我们一起
	让他们失迷
*/ 

