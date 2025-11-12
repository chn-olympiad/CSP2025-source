#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,k,u,v,w,dis[1010][1010],sum;
struct Node{LL u,d;};
vector<Node> g[1010];
void djs(LL u){
	queue<LL> q;
	for(LL i=1;i<=n;i++){
		
	}
	
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road .out","w",stdout);
	cin>>n>>m>>k;
	while(m--){
		scanf("%lld %lld %lld",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		sum+=w;
	}
	//djs(1);
	cout<<sum;
	return 0;
}
