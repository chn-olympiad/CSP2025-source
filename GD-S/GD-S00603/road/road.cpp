#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
const int N=1e4+5,M=1e6+5;
struct Edge{
	int u,v,w;	
}e[M];
struct cmp{
	Edge a,b;
	bool operator()(const Edge &a,const Edge &b){
		return a.w<b.w;
	}
};
int n,m,k,c[15],a[15][N],f[N],ans,num;
int find(int x){
	if (f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
void kruskal(){
	priority_queue<Edge,vector<Edge>,cmp> q;
	for (int i=1;i<=m;i++){
		q.push({e[i].u,e[i].v,e[i].w});
	}
	while (q.size()){
		Edge x=q.top();
		q.pop();
		int u=x.u,v=x.v,w=x.w;
		u=find(u);
		v=find(v);
		if (u!=v){
			f[u]=v;
			num++;
			for (int i=1;i<=k;i++){
				if (a[i][u]+a[i][v]+c[i]<w){
					ans+=a[i][u]+a[i][v]+c[i];
				}
				else ans+=w; 
			}
			if (num==n-1) return;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i].u=u,e[i].v=v,e[i].w=w;
	}
	for (int i=1;i<=k;i++){
		cin>>c[i];
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		f[i]=i;
	}
	kruskal();
	cout<<ans;
	return 0;
} 
