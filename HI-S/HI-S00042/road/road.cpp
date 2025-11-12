#include<cstdio>
#include<vector>
#include<queue>
const int maxN=1e4+10;
int n,m,k,ui,vi,wi,c[15],a[15][maxN];
std::vector<std::pair<int,int> > nxt[maxN];
std::queue<int> bfs;
bool vis[maxN];
long long ans=9223372036854775807;
void init(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&ui,&vi,&wi);
		nxt[ui].push_back((std::pair<int,int>){vi,wi});
		nxt[vi].push_back((std::pair<int,int>){ui,wi});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
}
void solve1(int now,long long nowans,int numvis){
	if(numvis==n){
		ans=std::min(ans,nowans);
		return;
	}
	vis[now]=true;
	for(std::vector<std::pair<int,int> >::iterator vt=nxt[now].begin();vt!=nxt[now].end();vt++){
		std::pair<int,int> i=*vt;
		if(vis[i.first]) continue;
		solve1(i.first,nowans+i.second,numvis+1);
	}
	vis[now]=false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	if(k==0) solve1(1,0LL,1);
	printf("%lld",ans);
	return 0;
}
