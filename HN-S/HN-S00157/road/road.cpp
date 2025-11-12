#include<bits/stdc++.h>
using namespace std;
#define N 10005
#define int long long
int T,n,m,k,ans,v[5],u[N];
struct nnn{
	int u,v,w;
};
vector<nnn>e[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,ph,gs,a,b,c;
	cin>>n>>m>>k;
	//不行了不写了呵呵呵呵呵 
	for(i=1;i<=m;i++){
		cin>>a>>b>>c;
		e[a].push_back(nnn{a,b,c});
		e[b].push_back(nnn{b,a,c});
	}
	return 0;
}
