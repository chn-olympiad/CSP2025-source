#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,fa[500005],tot,c[55],num[25][20005],ans,now,ls,res,cost;
struct edge{
	int u,v,w;
}r[5000005],e[500005],tr[500005];
inline bool cmp(edge x,edge y){
	return x.w<y.w;
}
inline int getfa(int x){
	if(fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		r[i]={x,y,z};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>num[i][j];
	}
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++){
		int fx=getfa(r[i].u),fy=getfa(r[i].v);
		if(fx==fy) continue;
		cnt++;
		fa[fx]=fa[fy];
		e[++tot]=r[i];
		ans+=r[i].w;
		if(cnt==n-1) break;
	}
//	for(int i=1;i<=tot;i++) cout<<e[i].u<<"  "<<e[i].v<<"  "<<e[i].w<<"\n";
	for(int i=1;i<(1<<k);i++){
		now=0,ls=0,res=0,cost=0;
		for(int p=1;p<=k;p++){
			if((i>>(p-1))&1) {
				ls++;
				cost+=c[p];
				for(int i=1;i<=n;i++) {
					tr[++now]={ls+n,i,num[p][i]};
				}
			}
		}
		for(int i=1;i<=tot;i++) tr[++now]=e[i];
		for(int i=1;i<=n+ls;i++) fa[i]=i;
		sort(tr+1,tr+now+1,cmp);
		cnt=0;
		for(int i=1;i<=now;i++){
			int fx=getfa(tr[i].u),fy=getfa(tr[i].v);
			if(fx==fy) continue;
			cnt++;
			fa[fx]=fa[fy];
			res+=tr[i].w;
			if(cnt==n+ls-1) break;
		}
		ans=min(ans,res+cost);
	}
	cout<<ans<<"\n";
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
