#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,K=12;
int n,m,k,f[N];
struct edge{
	int u,v,w;
	bool operator<(const edge&oth)const{
		return w<oth.w;
	}
};
vector<edge>g;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		f[fx]=fy;
	}
}
long long kru(){
	sort(g.begin(),g.end());
	long long cnt=n,ans=0;
	for(auto uvw:g){
		int u=uvw.u,v=uvw.v,w=uvw.w;
		if(find(u)!=find(v)){
			merge(u,v);
			ans+=w;
			cnt--;
		}
		if(cnt==0)break;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g.push_back({u,v,w});
		g.push_back({v,u,w});
	}
	bool pd=1,pdp;
	for(int j=1,c;j<=k;j++){
		pdp=0;
		cin>>c;
		if(c!=0)pd=0;
		for(int i=1,w;i<=n;i++){
			cin>>w;if(w==0)pdp=1;
			g.push_back({j+n,i,w+c});
			g.push_back({i,j+n,w+c});
		}
		pd&=pdp;
	}
	if(k==0){
		cout<<kru();
		return 0;
	}
	return 0;
} 
