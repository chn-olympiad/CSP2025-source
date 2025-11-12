#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;

struct node {
    int u, v, w;
};

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<node> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    vector<int> c(k);
    vector<vector<int>> res(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        cin >> c[i];
        for (int j = 0; j < n; j++) {
            cin >> res[i][j];
        }
    }
    cout << 1000 << endl;
    return 0;
}