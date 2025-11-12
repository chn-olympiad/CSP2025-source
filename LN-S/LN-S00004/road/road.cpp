#include <bits/stdc++.h>
using namespace std;
namespace WfhKing{void Main();}
signed main(){return WfhKing::Main(),0;}
namespace WfhKing
{
	#define int long long 
	const int N=1e4+7,M=1e6+7;
	struct node{int u,v,w;}edge[M],newedge[M];
	int n,m,k,c[15],ans = 0;
	int val[N],id[N];
	bool cmp(node a,node b){return a.w<b.w;}
	bool cmp2(int a,int b){return val[a] < val[b];}
	int fa[M],kval[15][N],kid[15][N];
	int check(int x){if(x == fa[x]) return x;return check(fa[x]);} 
	void solvefirst()
	{
		int cnt = 0,now = 0;
		for(int i=1;i<=n;i++) fa[i] = i;
		while(cnt != n-1)
		{
			++now;
			int x = edge[now].u,y = edge[now].v;
			if(check(x) == check(y)) continue;
			fa[fa[x]] = fa[y];
			newedge[++cnt] = edge[now];
			ans += edge[now].w;
		}
		return ;
	}
	bool iab[15];
	void solve2(int p)
	{
		if(p == k)
		{
			int cnt = n-1,nowans = 0,idcnt = n;
			for(int i=1;i<=k;i++)
				if(iab[i]){
					idcnt++;nowans+=c[i];
					for(int j=1;j<=n;j++) newedge[++cnt].u = idcnt,newedge[cnt].v = kid[i][j],newedge[cnt].w = kval[i][j];
				}
			sort(newedge+1,newedge+cnt+1,cmp);
			for(int i=1;i<=idcnt;i++) fa[i] = i;
			int tot = 0,now = 0;
			while(tot != idcnt-1)
			{
				++now;
				int x = newedge[now].u,y = newedge[now].v;
				if(check(x) == check(y)) continue;
				fa[fa[x]] = fa[y];tot++;
				nowans += newedge[now].w;
			}
			ans  = min(nowans,ans);
			//printf("%lld\n",nowans);
		}
		else
		{
			iab[p] = 1;solve2(p+1);
			iab[p] = 0;solve2(p+1);
		}
		return ;
	}
	void Main()
	{
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		scanf("%lld%lld%lld",&n,&m,&k);
		for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
		sort(edge+1,edge+m+1,cmp);
		solvefirst();
		//printf("%lld\n",ans);
		for(int i=1;i<=k;i++)
		{
			scanf("%lld",&c[i]);
			for(int j=1;j<=n;j++){scanf("%lld",&val[j]);id[j] = j;}
			sort(id+1,id+n+1,cmp2);
			for(int j=1;j<=n;j++) {kval[i][j] = val[id[j]],kid[i][j] = id[j];}
		}
		solve2(0);
		printf("%lld",ans);
		return ;
	}
}
