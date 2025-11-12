#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int f = 0;
    int n,m,k,u,v,w,c[1000005],a[1000005][1000005];
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i ++){
    	cin >> u >> v >> w;
    	f += w;
	}
	for(int i = 1;i <= k;i ++){
		cin >> c[i];
		for(int j = 1;j <= n; j ++){
			cin >> a[i][j];
		}
	}
	cout << f;
	return 0;
}

