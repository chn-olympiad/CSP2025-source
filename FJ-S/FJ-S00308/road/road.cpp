#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5;
int n,m,k,fa[N],ans;
ll c[15],a[15][N];
struct edge{
	int u,v;
	ll w;
};
vector <edge> e;
int find(int x){
	while(fa[x]!=x){
		fa[x]=fa[fa[x]];
		x=fa[x];
	}
	return x;
}
bool cmp(edge x,edge y){
	return x.w<=y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(u>v)swap(u,v);
		e.push_back({u,v,w});
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int o=1;o<=k;o++){
				e.push_back({i,j,c[o]+a[o][i]+a[o][j]});
			}
		}
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=0;i<e.size();i++){
		int x=e[i].u,y=e[i].v,z=e[i].w;
		if(x>y)swap(x,y);
		if(find(x)!=find(y)){
			ans+=z;
			fa[x]=find(y);
			fa[y]=find(y);
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/