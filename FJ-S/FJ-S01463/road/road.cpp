#include <bits/stdc++.h>
using namespace std;
vector <int> f;
int val[1000010];
void adde(int u,int v){
	f[u].push_back(v);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		adde(u,v);
		adde(v,u);
		val[i]=w;
	}
	sort(val+1,val+m+1);
	int ans=0;
	for(int i=1;i<=m-1;i++){
		ans+=val[i];
	}
	cout<<ans<<endl;
	return 0;
}
