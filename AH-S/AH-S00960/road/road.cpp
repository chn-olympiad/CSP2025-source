#include "bits/stdc++.h"
//Eason Cyj001001
#define int long long

using namespace std;

int n;
int m;
int k;
int u,v,w;
int sum;
int c;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++){
		cin >> u >> v >> w;
		sum += w;
	}
	for(int i=1; i<=k; i++){
		cin >> c;
		for(int j=1; j<=n; j++){
			cin >> c;
		}
	}
	cout << sum;
    return 0;
}
