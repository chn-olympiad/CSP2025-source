#include <bits/stdc++.h>
using namespace std;
int n,m,k,rcnt,cnt;
const int M=1e6+1e5+10;
const int N=1e4+30; 
struct Edge{
	int u,v;
	long long w;
	bool operator<(const Edge & b) const{
		return w<b.w;
	}
}edge[M],re[M];
int f[N],uk,vis[N];
long long a[15][N],c[N];
long long ans=LONG_LONG_MAX,rt=0;
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void kruskal(long long hac){
	//init;
	for(int i=1;i<=n+k+2;i++){
//		rt++;
		f[i]=i;
	}
	long long tmp=0;
	int ccnt=0;
	for(int i=1;i<=cnt;i++){
//		rt++;
		int u=re[i].u,v=re[i].v,w=re[i].w;
		if(find(u)!=find(v)){
			ccnt++;
			f[find(u)]=find(v);//merge
			tmp+=w;
			if(tmp+hac>=ans) break;//已经成为无用功了 
		}
		if(ccnt==n+uk-1){
			//已经成为连通图了
			break; 
		}
	}
	ans=min(ans,tmp+hac);
}
void dfs(int now,long long sum,int us){
	if(sum>=ans) return ;
	if(now==k+1){
		//开始累计
		cnt=0;
		for(int i=1;i<=m;i++){
//			rt++;
			cnt++;
			re[cnt]=edge[i];
		} 
		int cck=0;
		for(int i=1;i<=k;i++){
			if(!vis[i]) continue;
			++cck;
			for(int j=1;j<=n;j++){
//				rt++;
				re[++cnt]={n+cck,j,a[i][j]};
			}
		}
		sort(re+1,re+1+cnt);
		uk=us;
		kruskal(sum);
		return;
	}
	dfs(now+1,sum,us);
	vis[now]=1;
	dfs(now+1,sum+c[now],us+1);
	vis[now]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//洞爷保佑 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge[++rcnt]={u,v,w};
	}
	sort(edge+1,edge+1+rcnt);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;//AC 
}
