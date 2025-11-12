#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
int n,m,k;
struct edge{
	int u,v;
	ll w;
};
vector<edge> ed,ed1;
int wk[15][1005],w[15],fa[1050];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void add(int a,int b){
	fa[find(a)]=find(b);
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		ed.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>w[i];
		for(int j=1;j<=n;j++){
			cin>>wk[i][j];
		}
	}
	sort(ed.begin(),ed.end(),cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(edge x:ed){
		if(find(x.u)!=find(x.v)){
			ed1.push_back({x.u,x.v,x.w});
			add(x.u,x.v);
		}
	}
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++){
		ed.clear();
		ll ans1=0;
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				ans1+=w[j+1];
				for(int t=1;t<=n;t++){
					ed.push_back({n+j+1,t,wk[j+1][t]});
				} 
			}
		}
		if(ans1>=ans)continue;
		for(edge x:ed1){
			ed.push_back(x);
		}
		sort(ed.begin(),ed.end(),cmp);
		for(edge x:ed){
			if(find(x.u)!=find(x.v)){
				add(x.u,x.v);
				ans1+=x.w;
			}
		}
		ans=min(ans,ans1);
		
		
	}
	cout<<ans<<endl;
	return 0;
}
