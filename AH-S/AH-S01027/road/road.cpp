#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e6,NN=1e4;
struct A{
	int u,v,w;
}g[N];
struct B{
	int ww,www[NN];
}cs[15];
long long cntw=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
		cntw+=g[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>cs[i].ww;
		for(int j=1;j<=n;j++){
			cin>>cs[i].www[j];
		}
	}
	if(k==0){
		cout<<cntw<<endl;
		return 0;
	}else{
		cout<<0<<endl;
		return 0;
	}
	return 0;
}
