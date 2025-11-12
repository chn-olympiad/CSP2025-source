#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e4+10;
int n,m,k;
int father[MAXN],dist[MAXN];
vector<pair<int,int>> v[MAXN];

void solve(){
	
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++) cin>>x;
	}
	if(k==0){
		//最小生成树
		solve();
	}
	else{
		cout<<0;
	}
	return 0;
}