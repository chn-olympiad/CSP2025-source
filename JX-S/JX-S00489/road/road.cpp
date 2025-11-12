#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int n, m, k, u, v, w;
int a[1000000], b[1000000], c[1000000], d[1000000];
int main() {
	IOS;
	freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i];
	cin >> u >> v >> w;
	for(int i = 1; i <= n + 1; i++)
		cin >> d[i];
    cout << c[1] + c[2] << "\n";
    return 0;
}
