#include<bits/stdc++.h>
using namespace std;
using int64=long long;
bool _debug=false;
constexpr int maxN=10005;
int64 n,m,k,u,v,w,ans;
int64 fa[maxN];
struct E{
	int64 u,v,w;
	bool operator>(E a) const{
		return w>a.w;
	} 
	bool operator<(E a) const{
		return w<a.w;
	} 
};

int64 find(int n){
	if(fa[n]!=n){
		fa[n]=find(fa[n]);
		return fa[n];
	}else{
		return n;
	}
} 
void merge(int n,int m){
	fa[find(fa[n])]=find(m);
}

priority_queue<E,vector<E>,greater<E>> pq;
int main(){
	if(!_debug) {
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		if(u==v)continue;
		pq.push(E{u,v,w});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
//			cin>>c[i][j];
		}
	}
	while(!pq.empty()){
		E tp=pq.top();
		pq.pop();
//		cout<<fa[tp.u]<<' '<<fa[tp.v]<<endl;
		if((fa[tp.u]==0||fa[tp.v]==0)||(find(fa[tp.u])!=find(fa[tp.v]))){
			ans+=tp.w;
			
			if(fa[tp.u]==0&&fa[tp.v]==0){
				fa[tp.u]=tp.u;
				fa[tp.v]=tp.u;
			}else if(fa[tp.u]==0){
				fa[tp.u]=find(tp.v);
			}else if(fa[tp.v]==0){
				fa[tp.v]=find(tp.u);
			}else{
				merge(tp.u,tp.v);
			}
			
		}
	}
	cout<<ans;
	return 0;
} 
