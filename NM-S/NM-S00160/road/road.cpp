// 我受不了了我J都没过让我来考S什么误闯天家我再也不来考S了
#include <bits/stdc++.h>
using namespace std;
#define int long long
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> u(m), v(m), w(m);
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }
    vector<int> c(k);
    int a[10][10000];
    for (int j; j < k; j++) {
        cin >> c[j];
        for (int b = 0; b < n; b++) {
            cin >> a[j][b];
        }
    }
    return 0;
}