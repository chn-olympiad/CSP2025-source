#include<bits/stdc++.h>
using namespace std;
const int N=10010,M=2000010;
int n,m,k,u[M],v[M],d[N];
long long w[M],ans=1e18,c[N],a[20][N];
pair<int,long long>g[400010]; 
struct node{
	int u,v;
	long long w;
}e[3000010];
bool cmp(node a,node b){
	return a.w<b.w;
}

bool vis[15];
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int a=find(x),b=find(y);
	fa[b]=a;
}
void kruskal(){
	long long sum=0;
	int tp=0,p=n;
	for(int i=1;i<=m;i++){
		e[++tp]={u[i],v[i],w[i]};
	}
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		if(vis[i]){
			sum+=c[i];
			p++;
			for(int j=1;j<=n;j++){
				e[++tp]={j,n+i,a[i][j]};
			}
		}
	}
	sort(e+1,e+1+tp,cmp);
	int tmp=0;
	for(int i=1;i<=tp;i++){
		int u=e[i].u,v=e[i].v;
		long long w=e[i].w;
		if(find(u)==find(v)) continue;
		sum+=w;
		tmp++;
		merge(u,v);
		if(tmp>=p-1){
			ans=min(ans,sum);
			return;
		}
	}
}
//void prim(){
//	for(int i=1;i<=n+k;i++) fa[i]=i;
//	long long sum=0;
//	int tp=0,p=n;
//	for(int i=1;i<=k;i++){
//		if(vis[i]){
//			sum+=c[i];
//			p++;
//		}
//	}
//	vis[1]=1;
//	for(int i=1;i<p;i++){
//		
//	}
//}
void dfs(int st){
	if(st>k){
		kruskal();
		return;
	}
	vis[st]=1;
	dfs(st+1);
	if(c[st]!=0){
		vis[st]=0;
		dfs(st+1);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
//		d[u[i]]++,d[v[i]]++;
	}
//	for(int i=1;i<=n;i++) d[i+1]+=d[i];
//	for(int i=1;i<=m;i++){
//		g[--d[u[i]]]={v[i],w[i]};
//		g[--d[v[i]]]={u[i],w[i]};
//	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	dfs(1);
	cout<<ans;
	return 0;
}

