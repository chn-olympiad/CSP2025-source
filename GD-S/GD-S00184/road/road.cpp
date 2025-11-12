#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
bool vis[15];
int fa[10005],n,m,k,u,v,w;
long long ans;
struct Edge{
	int u,v,w,extra;
};
int get(int x){
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)]=get(y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	vector<Edge> l;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		l.push_back({u,v,w,0});
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			l.push_back({n+i,j,a,x});
		}
	}
	sort(l.begin(),l.end(),[](Edge x,Edge y){return x.w+x.extra<y.w+y.extra;});
	for(Edge i:l){
		if(get(i.u)!=get(i.v)){
			merge(get(i.u),get(i.v));
			if(i.u>n) ans+=i.w+(1-vis[i.u])*i.extra;
			else ans+=i.w;
			vis[i.u]=1;
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
