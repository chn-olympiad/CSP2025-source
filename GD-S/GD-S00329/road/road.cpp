#include<bits/stdc++.h>
using namespace std;
const int N=1e3+51;
int n,m,k,fa[N];
long long ans,e[N][N];
struct Node{
	int u,v;
	long long w;
	bool operator <(const Node &other) const{
		return w<other.w;
	}
};
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
vector<Node>edge;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	memset(e,0x3f,sizeof(e));
	for(int i=1;i<=m;i++){
		int u,v;
		long long w;
		cin>>u>>v>>w;
		e[u][v]=min(e[u][v],w);
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		long long edge_[N];
		for(int j=1;j<=n;j++){
			long long w;
			cin>>w;
			edge_[j]=w;
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n&&k!=j;k++){
				e[j][k]=min({e[j][k],e[k][j],edge_[j]+edge_[k]+c});
				edge.push_back((Node){j,k,e[j][k]});
			}
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(edge.begin(),edge.end());
	int cnt=1;
	for(Node e:edge){
		int u=e.u,v=e.v;
		long long w=e.w;
		u=find(u),v=find(v);
		if(u==v) continue;
		cnt++;
		fa[v]=u;
		ans+=w;
		if(cnt==n) break;
	}
	cout<<ans;
	return 0;
}
/*
road n<=1000,´øÆ«²î,kruskal°æ 

Ô¸´ËÐÐ,ÖÕµÖÈºÐÇ ÈªÃÅÓÀ´æ
I love ldyy 
icebird_ldyy code
*/
