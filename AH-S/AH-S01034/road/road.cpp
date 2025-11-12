#include <bits/stdc++.h>
using namespace std;
int n, m, k, dp[1000005][105];
struct node{
	int u, v, w;
}a[1000005];
struct ax{
	int s, x, y, z, f;
}b[15];
bool cmp(node A, node B){
	return A.w < B.w;
}
bool cm(ax C, ax D){
	return C.s < D.s;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i ++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	sort (a + 1, a + n + 1, cmp);
	for (int j = 1;j <= k;j ++){
		cin >> b[j].s >> b[j].x >> b[j].y >> b[j].z >> b[j].f;
	}
	sort (b + 1, b + n + 1, cm);
	dp[1][1] = 0;
	for (int i = 1;i <= m;i ++){
	    for (int j = 1;j <= k;j ++){
		    dp[i][j] = min(dp[i][j], dp[i + a[i].w][j] - a[i].w);
	    }
    }
    cout << dp[m][k];
    return 0;
}
