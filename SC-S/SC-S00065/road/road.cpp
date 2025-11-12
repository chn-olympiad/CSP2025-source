#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e6;
int n,m,k,sum,tmp,vis[10006];
int c[16][100006],u[10006],v[10006],w[10006],a[1006][1006];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 0;i < n;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	memset(a,inf,sizeof(a));
	if(k == 0){
	    for(int i = 0;i < n;i++){
			a[u[i]][v[i]] = w[i];
		}
		for(int i = 0;i < n;i++){
			if(!vis[u[i]] && !vis[v[i]]){
				sum += min(a[u[i]][v[i]],a[v[i]][u[i]]);
			    vis[u[i]] = vis[v[i]] = 1;
			}
		}
		cout << sum << endl;
		return 0;
	}else{
		for(int i = 0;i < k;i++){
			cin >> tmp;
			c[i][0] = tmp;
			for(int j = 1;j < n;j++){
				cin >> c[i][j];
			}
		}
	}
	return 0;
} 