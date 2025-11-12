#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1000005,N=10025;
int n,m,k,ans;
struct node{
	int id,to,w;
}e[M*2];
bool cmp(node x,node y){
	return x.w<y.w;
}
int cnt;
int f[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
struct node1{
	int id,w;
	bool operator<(const node1 other) const{
		if(other.w!=w)return other.w<w;
		else return (other.id>id);
	}
};
int c[N],cc[N];
priority_queue<node1> t;
struct edge{
	int to,w;
};
vector<edge> g[N];
int q[N];
bool vis[N],vis1[N];
void dij(){
	for(int i=2;i<=n+k;i++){
		c[i]=INT_MAX;
	}
	t.push({1,0});
	while(!t.empty()){
		int x=t.top().id;
		t.pop();
		if(vis[x]==1)continue;
		vis[x]=1;
		for(edge j:g[x]){
			int v=j.to;
			int w=j.w;
			if(v>n){//乡村 
				w+=cc[v-n];
			}
			if(c[x]+w<c[v]){
				q[v]=x;//前继点 
				c[v]=c[x]+w;
				t.push({v,c[v]});
			}
		}
	}
}
int a[11][N];
int ii,iii,iiii;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		for(int i=1;i<=m;i++){
			scanf("%lld%lld%lld",&ii,&iii,&iiii);
			e[++cnt]={ii,iii,iiii};	
		}
		sort(e+1,e+cnt+1,cmp);
		int s=0;
		for(int i=1;i<=cnt&&s!=n-1;i++){
			int u=find(e[i].id);
			int v=find(e[i].to);
			if(u!=v){
				s++;
				f[u]=v;
				ans+=e[i].w;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	else{
		for(int i=1;i<=m;++i){
			scanf("%lld%lld%lld",&ii,&iii,&iiii);
			e[++cnt]={ii,iii,iiii};
			g[ii].push_back({iii,iiii});
			g[iii].push_back({ii,iiii});
		}
		for(int i=1;i<=k;++i){
			scanf("%lld",&cc[i]);
			for(int j=1;j<=n;j++){
				scanf("%lld",&a[i][j]);
				g[i+n].push_back({j,a[i][j]});
				g[j].push_back({i+n,a[i][j]});
			}
		}
		dij();
		for(int i=1;i<=n;++i){
			if(q[i]>n){//当前点有用 
				vis1[q[i]]=1;
			}
		}
		int p=0;
		for(int i=n+1;i<=n+k;++i){
			if(vis1[i]==1){//当前点有用 
				for(int j=1;j<=n;j++){
					e[++cnt]={i,j,a[i-n][j]};
				}
				p++;
				ans+=cc[i-n];
			}
		}
		stable_sort(e+1,e+cnt+1,cmp);
		int s=0;
		for(int i=1;i<=n+k;++i){
			f[i]=i;
		}
		for(int i=1;i<=cnt&&s<n+p-1;++i){
			int u=find(e[i].id);
			int v=find(e[i].to);
			if(u!=v){
				f[u]=v;
				ans+=e[i].w;
				s++;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
