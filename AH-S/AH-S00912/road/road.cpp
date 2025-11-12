#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans,w[1000005];
vector <pair<int,int>> a[11005] ;
void add(int u,int v,int w){
	a[u].push_back({v,w});
}
void bfs(){
	queue <pair<int,int>> q;
	//q.push_back({a[1].top().v,a[1].top().w});
	while(q.empty()){
		
	}
}
signed main(){
//	freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int v,u;
		cin>>v>>u>>w[i];
		add(v,u,w[i]);
		add(u,v,w[i]);
	}
	for(int i=1;i<=k;i++){
		int c,w2;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>w2;
			//~ add(j,c,w);
		    //~ add(c,j,w);
		}
	}
	sort(w+1,w+m+1);
	for(int i=1;i<n;i++){
		ans+=w[i];
	}
	bfs();
	cout<<ans;
	return 0;
} 
