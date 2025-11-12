#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
};
vector<edge>e;
int fa[100005];

int fd(int x){
	if(fa[x]==x)return x;
	else return fd(fa[x]);
}
void Union(int x,int y){
		x=fd(x),y=fd(y);
		fa[x]=y;
}
bool cmp(edge x,edge y){
	if(x.w==y.w)return x.u>y.u;
	return x.w<y.w;
}
int ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
		e.push_back({v,u,w});
		
	}
	int c,a;
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int i=1;i<n;i++){
			cin>>a;
		}
	}
		sort(e.begin(),e.end(),cmp);
		for(int i=1;i<=e.size();i++){
			if(fd(e[i].u)!=fd(e[i].v)){
				ans+=e[i].w;
				Union(e[i].u,e[i].v);
				
			}
		}
		cout<<ans;		
	return 0;
}
