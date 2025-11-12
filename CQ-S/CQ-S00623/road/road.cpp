#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e4+55;
const int N = 1e4+55;
const int K = 1<<10;
int n,m,k,c[10];
ll tmp[K],ans,sum;
struct node{
	int u,v,w;
}e[K][N],el[10][N],E[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
node eb[1000005];
int cnt[K],tot;
bool vis[K];
int f[M*2];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(node ep){
	int u=find(ep.u),v=find(ep.v);
	if(u!=v)E[++tot]=ep,sum+=ep.w,f[u]=v;
}
void zxscs(int s,int t){
	for(int i=1;i<=n+k;i++)f[i]=i;
	sum=tot=0;
	for(int i=1,j=1;i<=cnt[s];i++){
		while(j<=n&&el[t][j].w<=e[s][i].w){
			merge(el[t][j]);
			j++;
		}
		merge(e[s][i]);
	}
	for(int i=1;i<=tot;i++)e[s][i]=E[i];
	cnt[s]=tot;
}
void dfs(int s){
	if(vis[s])return;
	vis[s]=1;
	for(int i=0;i<k;i++){
		if(!(s>>i&1)){
			int o=s|(1<<i);
			for(int j=1;j<=cnt[s];j++)e[o][j]=e[s][j];
			cnt[o]=cnt[s],tmp[o]=tmp[s]+c[i];
			zxscs(o,i);
			ans=min(ans,sum+tmp[o]);
			dfs(o);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>eb[i].u>>eb[i].v>>eb[i].w;
	}
	
	sort(eb+1,eb+1+m,cmp);
	for(int i=1;i<=n+k;i++)f[i]=i;
	sum=0;
	for(int i=1,j=1;i<=m;i++){
		merge(eb[i]);
	}
	ans=sum;
	cnt[0]=tot;
	for(int i=1;i<=tot;i++){
		e[0][i]=E[i];
	}
	
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>el[i][j].w;
			el[i][j].u=n+i+1,el[i][j].v=j;
		}
		sort(el[i]+1,el[i]+1+n,cmp);
	}
	dfs(0);
	cout<<ans;
}
