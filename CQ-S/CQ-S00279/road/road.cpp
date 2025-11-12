#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,k;
int c[1005];
int dist[5050];
struct aaa{
	int to;
	int val;
};
vector<aaa> g[1005];
//忘了最小生成树怎么打了 怎么办...... 
//完蛋了www，唯有的48分被吃了 
void solve(){
	int s=0;
	memset(0x3f3f,dist,sizeof(dist));
	
}

signed main(){
    // freopen("road.in","r",stdin);
    // freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
     
    cin>>n>>m>>k;
    int s=n;
    for(int i=1;i<=m;i++){
    	int v,u,k;
    	cin>>u>>v>>k;
    	g[u].push_back({v,k});
    	g[v].push_back({u,k});
	}
    for(int i=1;i<=k;i++){
    	cin>>c[i];
    	s++;
    	for(int i=1;i<=n;i++){
    		int x;
    		cin>>x;
    		g[i].push_back({s,x});
    		g[s].push_back({i,x});
		}
	}
    return 0;
}
//a[j][i]=0
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

