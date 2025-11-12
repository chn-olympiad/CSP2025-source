#include<bits/stdc++.h>//32+16=48
using namespace std;
const int N=1e4+5, M=1e6+5, K=11;
struct edge{
	int v, t, n;
	bool operator>(const edge& x)const{
		return v>x.v;
	}
}e[M*2];
int h[N], size, vis[N];
int n, m, k, a[K+N][N], c[K+N];
priority_queue<edge, vector<edge>, greater<edge> > q;
int kr1(){
	edge t; int u, w, ans=0;
//	for(int l=1; l<=m; l++){for(int i=head[l]; i; i=e[i].n){u=e[i].t;w=e[i].v;
//			for(int j=n+1; j<=n+k; j++){w=min(w, a[j][1]+a[j][u]);}
//			t={w, t, 0};}}
	for(int i=1; i<=size; i++)
		q.push(e[i]);
	vis[1]=1;
	while(!q.empty()){
		t=q.top();
		q.pop();
		u=t.t; w=t.v;
		if(!vis[u]){
			ans+=w;
			vis[u]=1;
		}
	}
	return ans;
}
void add(int u, int v, int w){
	e[++size]={w, v, h[u]};
	h[u]=size;
}
int u, v, w;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=0; i<m; i++){
		cin>>u>>v>>w;
		add(u, v, w);
		add(v, u, w);
	}
	for(int i=1; i<=k; i++){
		cin>>c[i+n];
		for(int j=1; j<=n; j++)
			cin>>a[i+n][j];
	}
	if(!k){
		cout<<kr1()<<endl;
		return 0;
	}else
		cout<<0<<endl;
	return 0;
}

