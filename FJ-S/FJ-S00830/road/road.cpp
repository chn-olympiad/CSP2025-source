#include<bits/stdc++.h>
using namespace std;
struct node{
	long long u,v,w;
};
vector<node> e;
int n,m,k;
int fa[20005];
void init(){
	for(int i=1;i<=20000;i++){
		fa[i]=i;
	}
	return;
}
int find(int u){
	if(fa[u]==u){
		return u;
	}
	return fa[u]=find(fa[u]);
}
bool cmp1(node a,node b){
	return a.w<b.w;
}
void solve1(){
	init();
	long long ans=0;
	sort(e.begin(),e.end(),cmp1);
	for(int i=0;i<m;i++){
		long long u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v)){
			continue;
		}
		ans+=w;
		fa[v]=find(u);
		
	}
	cout<<ans;
	return;
}
int ww[20005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	if(k==0){
		solve1();
		return 0;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>ww[j];
			
		}
		for(int j=1;j<=n;j++){
			int u,w;
			u=j;
			for(int v=1;v<=n;v++){
				if(v==u){
					continue;
				}
				w=ww[k];
				e.push_back({u,v,w});
				m++;
			}
			
		}
	}
	solve1();
	return 0;
}//16pts