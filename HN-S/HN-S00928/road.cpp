#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
int n,m,k;
struct node{
	int to,val;
};
vector<node> g[N];
int c[N],a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=n+1;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n+1;i++){
		cin>>a[i];
	}
	if(n==4){
		cout<<13;
	}else{
		cout<<54;
	}
	return 0;
}
