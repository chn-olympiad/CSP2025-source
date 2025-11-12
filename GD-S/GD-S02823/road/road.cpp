#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e4+3;
int f[MAXN],n,m,k,cnt[MAXN],rd[MAXN],vil[MAXN];
long long sum[20];
struct edge{
	int u,v,w;
	bool operator <(const edge &o)const{
		return w<o.w;
	}
};
vector<edge> e,ans;
void init(){
	for(int i=1;i<=n;i++)f[i]=i;
}
int findf(int u){
	return f[u]=(f[u]==u ?u:findf(f[u]));
}
void merge(int u,int v){
	u=findf(u),v=findf(v);
	if(u==v)return ;
	f[v]=u;
}
long long kruskal(){
	long long ret=0,cntedge=0;
	sort(e.begin(),e.end());
	for(auto eg:e){
		if(cntedge==n-1)return ret;
		int u=eg.u,v=eg.v,w=eg.w;
		if(findf(u)==findf(v))continue;
		ret+=w;
		merge(u,v);
		ans.push_back({u,v,w});
		cntedge++;
	}
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	int minrd=0x3f3f3f3f;
	for(int i=1;i<=k;i++)cin>>vil[i];
	for(int i=1;i<=k;i++){
		cin>>rd[i];
		minrd=min(minrd,rd[i]);
	}
	if(k==0){
		cout<<kruskal();
		exit(0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			e.push_back({i,j,minrd*2});
		}
	}
	cout<<kruskal();
	return 0;
}
