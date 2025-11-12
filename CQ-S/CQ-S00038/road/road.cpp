#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define N 10005
struct edge{
	int u;
	int v;
	double w;
};
bool operator <(const edge &a,const edge &b){
	return a.w>b.w;
}
int f[N];
int a[N];
double c[15];
bool vis[15];
long double s=0;
int n,m,k;
int u,v,w;
priority_queue<edge>pq;
int find(int x){
	if(x==f[x]) return f[x];
	f[x]=find(f[x]);
	return f[x];
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy) f[fx]=fy;
}
void kruskal(){
	while(pq.size()){
		edge e=pq.top();
		pq.pop();
		if(find(e.u)!=find(e.v)){
			merge(e.u,e.v);
			s+=e.w;
		}
	}
}
void kruskal2(){
	while(pq.size()){
		edge e=pq.top();
		pq.pop();
		if(find(e.u)!=find(e.v)){
			if(e.u>n) vis[e.u-n]=1;
			if(e.v>n) vis[e.v-n]=1;
			merge(e.u,e.v);
			s+=e.w;
		}
	}
}
void doing(){
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>u>>v>>w;
			pq.push({u,v,w});
		}
		for(int i=1;i<=n;i++) f[i]=i;
		kruskal();
		cout<<(long long)s;
		return;
	}
	else{
		for(int i=1;i<=m;i++){
			cin>>u>>v>>w;
			pq.push({u,v,w});
		}
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				cin>>a[i];
				pq.push({n+i,j,a[i]+c[i]/2});
			}
		}
		for(int i=1;i<=n;i++) f[i]=i;
		kruskal2();
		cout<<(long long)s;
		return;
	} 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	doing();
	return 0;
}
