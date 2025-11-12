#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
struct edge{
	int u,v,w;
};
vector<edge> g;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int fa[maxn];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin >> n >> m >> k;
	for(int i=0;i<=n;i++)fa[i]=i;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g.push_back({u,v,w});
	}
	sort(g.begin(),g.end(),cmp);
	for(auto i:g){
		if(find(i.u)!=find(i.v)){
			fa[find(i.u)]=find(i.v);ans+=i.w;
		}
		
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
