#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mkp make_pair
using namespace std;

const int MAXN=1e4+25;
const int MAXM=1e6+5;

int n,m,k;
struct EDGE{
	int u,v,w;
}edge[MAXM],e2[15][MAXN];

bool cmp(EDGE x,EDGE y){
	return x.w<y.w;
}

int fa[MAXN],siz[MAXN];
int cost[15];
void init(){
	for(int i=1;i<=n+k;++i) fa[i]=i,siz[i]=1;
}int find(int x){
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return ;
	if(siz[x]<siz[y]) swap(x,y);
	fa[y]=x;siz[x]+=siz[y];
}//

bitset<15> vis;
int top[15];
priority_queue<pii > q;

ll Kruskal(int kk){
	ll sum=0;
	int cnt=0;
	sum=0;
	
	init();
	int u,v,w;
	while(!q.empty()) q.pop();
	for(int i=0;i<=k;++i) if(vis[i]) top[i]=1;
	for(int i=1;i<=k;++i) if(vis[i]) q.push(mkp(-e2[i][1].w,i));
	q.push(mkp(-edge[1].w,0));
	int p;
	EDGE t;
	
	while(cnt<n+kk-1){
		p=q.top().second;q.pop();
		if(p==0) t=edge[top[p]];
		else t=e2[p][top[p]];
		++top[p];
		if(p==0){
			if(top[p]<=m) q.push(mkp(-edge[top[p]].w,0));
		}else{
			if(top[p]<=n) q.push(mkp(-e2[p][top[p]].w,p));
		}
		
		u=t.u;v=t.v;w=t.w;
		if(find(u)==find(v)) continue;
		++cnt;
		sum+=w;
		merge(u,v);
		if(cnt==n+kk-1) break;
	}
	return sum;
}//

ll ans=2e18;

void dfs(int idx,ll c,int num){
	if(idx>k){
//		for(int i=1;i<=k;++i) printf("%d",vis[i]==1); 
//		printf("[%d]%lld\n",num,Kruskal(num)+c);
		ans=min(ans,Kruskal(num)+c);
		return ;
	}
	vis[idx]=1;
	dfs(idx+1,c+cost[idx],num+1);
	vis[idx]=0;
	dfs(idx+1,c,num);
}//

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=k;++i){
		scanf("%d",&cost[i]);
		for(int j=1;j<=n;++j){
			scanf("%d",&e2[i][j].w);
			e2[i][j].u=n+i;
			e2[i][j].v=j;
		}
		sort(e2[i]+1,e2[i]+1+n,cmp);
	}
	vis[0]=1;
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
