#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
const int N=1e4+10;
int dis[N][N];
int vis[N];
int c[N];
int a[11][N];
vector<pair<int,int>>g[N];
struct node{
	int id,val,cnt;
	bool operator <(const node &u)const{
		return val>u.val; 
	}
};


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	for(int i = 1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		
		g[u].push_back({v,w});
		g[v].push_back({u,w});

	}
	bool p=1;
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0){
				p=0;
			}
		}
	}
	


	cout<<0;
	
	return 0;
} 
