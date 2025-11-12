#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int n,m,k;
struct node{
	int u,v,w;
}e1[MAXN];
struct edge{
	int v,w;
};
vector<edge> e[MAXN];
bool cmp(node x,node y){
	return x.w<y.w;
}

int fa[MAXN];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int sum1;
void kurskal(){
	for(int i=1;i<=m;i++){
		int u=e1[i].u,v=e1[i].v,w=e1[i].w;
		if(find(u)==find(v)) continue;
		fa[find(u)]=find(v);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		sum1+=w;
	}
}
int lg[MAXN];
int dg[MAXN];
int dp[MAXN][32];
int sum[MAXN];
void dfs(int x,int fa){
//	cout<<x<<" "<<sum[x]<<endl;
	dp[x][0]=fa;dg[x]=dg[fa]+1;
	for(int i=1;i<=lg[dg[x]];i++)
		dp[x][i]=dp[dp[x][i-1]][i-1];
	for(int i=0;i<e[x].size();i++){
		int v=e[x][i].v,w=e[x][i].w;
		if(v==fa||v==-1) continue;
		sum1+=w;
		sum[v]=sum[x]+w;
		dfs(v,x);
	}
}
bool f[MAXN];
int a[MAXN];
int LCA(int x,int y){
	if(dg[x]<dg[y]) swap(x,y);
	while(dg[x]>dg[y])
		x=dp[x][lg[dg[x]-dg[y]]];
	if(x==y) return x;
	for(int i=lg[dg[x]-dg[y]];i>=0;i--)
		if(dp[x][i]!=dp[y][i])
			x=dp[x][i],y=dp[y][i];
	return dp[x][0];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout)
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e1[i].u>>e1[i].v>>e1[i].w;
	sort(e1+1,e1+1+m,cmp);
	kurskal();
	if(k==0){
		cout<<sum1<<endl;
		return 0;
	}
	cout<<0<<endl;
	lg[0]=1;
//	for(int i=1;i<=n+k;i++) lg[i]=lg[i/2]+1;
//	
//	for(int i=1;i<=k;i++){
//		int c;cin>>c;
//		for(int i=1;i<=n;i++) cin>>a[i];
//		dfs(1,0);
//		int res=0;
//		for(int u=1;u<=n;u++)
//			for(int v=u+1;v<=n;v++){
//				int f=LCA(u,v);
//				int w=sum[u]+sum[v]-sum[f];
//				int maxn=0,pos=0;
//				int temp1=u,temp2=v;
//				while(u!=f){
//					if(maxn<sum[dp[u][0]]-sum[u]){
//						maxn=sum[dp[u][0]]-sum[u];
//						pos=u;
//					}
//					u=dp[u][0];
//				}while(v!=f){
//					if(maxn<sum[dp[v][0]]-sum[v]){
//						maxn=sum[dp[v][0]]-sum[v];
//						pos=v;
//					}
//					v=dp[v][0];	
//				}
//				u=temp1,v=temp2;
//				if(a[u]+a[v]-maxn<0){
//					res+=maxn-a[u]-a[v];
//					a[u]=0,a[v]=0;
////					f[pos]=true;
//					e[u].push_back({n+i,a[u]});
//					e[v].push_back({n+i,a[v]});
//					e[n+i].push_back({u,a[u]});
//					e[n+i].push_back({v,a[v]});
//					for(int i=1;i<=e[pos].size();i++)
//						if(e[pos][i].v==dp[pos][0])
//							e[pos][i].v=-1;
//					for(int i=1;i<=e[dp[pos][0]].size();i++)
//						if(e[dp[pos][0]][i].v==pos)
//							e[dp[pos][0]][i].v=-1;
////					cout<<u<<" "<<v<<endl<<pos<<endl;
//				}
//				sum1=0;
//				cout<<endl;
//				dfs(1,0);
//			}
//	}
//	sum1=0;
//	dfs(1,0);
//	cout<<sum1<<endl;
	return 0;
}
