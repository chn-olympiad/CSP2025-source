#include<bits/stdc++.h>
using namespace std;
const int N=1e4+9,K=10+9;
const long long MAXN=1e18+9;
int n,m,k;
long long tot,ans=MAXN;
long long chang[K];
struct node{ long long start,end,val,f;};
vector<node> e[2];
bool cmp(node &x,node &y){ return x.val<y.val; }
bool vis[K];int fa[N+K];
int find_fa(int x){ return (fa[x]==x) ? x:fa[x]=find_fa(fa[x]); }
void solve(int d,int cnt,int f){
	int add=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=0;i<m;i++){
		node now=e[f][i];
		if(now.f!=-1&&((d&(1<<(now.f-1)))==0)) continue;
		int u=find_fa(now.start),v=find_fa(now.end);
		if(u!=v){
			fa[u]=v,tot+=now.val,add++;
			if(f==0) e[1].push_back(now);
		}
	}
	if((cnt-1)!=add) tot=MAXN;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,sx,sy,sz;i<=m;i++){
		scanf("%d%d%d",&sx,&sy,&sz);
		e[0].push_back(node{sx,sy,sz,-1});
	}
	sort(e[0].begin(),e[0].end(),cmp);solve(0,n,0);
	for(int i=1;i<=k;i++){
		scanf("%lld",&chang[i]);
		for(int j=1,sx;j<=n;j++){
			scanf("%d",&sx);
			e[1].push_back(node{n+i,j,sx,i});
		}
	}
	sort(e[1].begin(),e[1].end(),cmp);m=e[1].size();
	for(int key=0;key<(1<<k);key++){
		int ex=0;tot=0;memset(vis,0,sizeof(vis));
		for(int i=1;i<=k;i++) if((key&(1<<(i-1)))!=0){
			ex++,vis[i]=true,tot+=chang[i];
		}
		solve(key,n+ex,1);ans=min(ans,tot);
	}
	printf("%lld\n",ans);
	return 0;
} 