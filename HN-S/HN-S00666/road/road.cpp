#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100007;
struct Node{
	int u,v,w;
}edge[maxn];
int n,m,k;
bool vis[maxn];
bool cmp(Node a,Node b) {
	return a.w<b.w;
}
int fa[maxn],p[maxn];
int find(int x) {
	if(x==fa[x]) {
		return x;
	}
	return fa[x]=find(fa[x]);
}
void kruskal() {
	for(int i=1;i<=n+k;i++) {
		fa[i]=i;
	}
	int sum=0,cnt=0;
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=m;i++) {
//		cout<<cnt<<'\n';
		if(cnt==n) {	
			break;
		}
		cout<<edge[i].u<<' '<<edge[i].v<<' '<<edge[i].w<<'\n';
		int u=find(edge[i].u),v=find(edge[i].v),w=edge[i].w;
		cout<<u<<' '<<v<<' '<<w<<'\n';
		if(u!=v) {
			sum+=w;
			fa[u]=v;
			if(u>=1&&u<=n&&!vis[u]) {
				cnt++;
			}
			if(v>=1&&v<=n&&!vis[v]) {
				cnt++;
			}
			if(u>n&&vis[u]) {
				sum-=p[u];
			}
			if(v>n&&vis[v]) {
				sum-=p[v];
			}
			vis[u]=vis[v]=1;
		}
	}
	cout<<sum<<'\n';
	return ;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		int w;
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	if(k==0) {
		kruskal();
		return 0;
	}
	for(int i=1;i<=k;i++) {
		cin>>p[i+n];
		for(int j=1;j<=n;j++) {
			int w;
			cin>>w;
			edge[++m].u=i+n,edge[m].v=j,edge[m].w=w+p[i+n];
		}
	}
	kruskal();
	return 0;
}
