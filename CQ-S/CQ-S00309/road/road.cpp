#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e16;
struct Node {
    int x, y, z, op;
} edge[2000005];
int n, m, k, cnt, c[15], f[10005], sum[(1 << 10) | 5];
bool SUBA;
int get_father(int x) {
    return f[x] == x ? x : f[x] = get_father(f[x]);
}
bool MMM(Node x, Node y) {
    return x.z < y.z;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) {
        cin >> edge[++cnt].x >> edge[cnt].y >> edge[cnt].z;
		edge[cnt].op = 0;
    }
    for (int i = 1; i <= k; i ++) {
        cin >> c[i];
        if (c[i] != 0) {
            SUBA = true;
        }
        for (int j = 1; j <= n; j ++) {
            int x;
            cin >> x;
            if (x != 0) {
                SUBA = true;
            }
            edge[++cnt].x = i + n;
            edge[cnt].y = j;
            edge[cnt].z = x;
            edge[cnt].op = i;
        }
    }
//    if (n <= 1000) {
        for (int i = 0; i < (1 << k); i ++) {
            for (int j = 0; j < k; j ++) {
            	if (i & (1 << j)) {
            	    sum[i] += c[j + 1];
            	}
        	}
    	}
		int SSS = 0, ans = INF;
		sort(edge + 1, edge + 1 + cnt, MMM);
		for (int i = 0; i < (1 << k); i ++) {
			for (int j = 1; j <= n + k; j ++) {
				f[j] = j;
			}
			SSS = 0;
			for (int j = 1; j <= cnt; j ++) {
				if (edge[j].op && !(i & (1 << (edge[j].op - 1)))) {
					continue;
				}
				// cout << edge[j].op << "\n";
				int fx = get_father(edge[j].x), fy = get_father(edge[j].y);
           		if (fx != fy) {
            	    f[fx] = fy;
            	    SSS += edge[j].z;
            	}
			}
			ans = min(ans, SSS + sum[i]);
			// cout << ans << " " << i << "\n";
			// cout << "####\n";
		}
		cout << ans << "\n";
		return 0;
//    }
	
    return 0;
}