#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n,m,k;
struct node{
	int from,to,val;
	bool operator < (const node &other)const{
		return val<other.val;
	}
};
vector<node> path; 
int c[20],f[maxn];
long long ans;
#define union Union
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void union(int x,int y){
	int gx=find(x),gy=find(y);
	if(gx!=gy) f[gy]=gx;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i){
		cin>>u>>v>>w;
		path.push_back({u,v,w});
		path.push_back({v,u,w});
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1,w;j<=n;++j){
			cin>>w;
			path.push_back({i+n,j,w});
			path.push_back({j,i+n,w});
		}
	}
	sort(path.begin(),path.end());
	for(int i=1;i<=n;++i) f[i]=i;
	int nn=path.size();
	for(int i=1;i<=nn;++i){
		if(find(path[i].from)!=find(path[i].to)){
			union(path[i].from,path[i].to);
			ans+=path[i].val;
		}
	}
	cout<<ans;
	return 0;
}
