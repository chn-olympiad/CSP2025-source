#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define endl "\n"
#define MOD 998244353
using namespace std;
const int N = 5e3 + 1;
int n, a[N], cnt = 0;
bool b[N];
vector<int> d;
void dfs(int x, int ans, int maxn, int l) {
    if(x >= 3 && ans > maxn * 2)
        cnt = (cnt + 1) % MOD;
    for(int i = l; i <= n; i++) {
        if(!b[i]) {
            b[i] = 1;
            d.emplace_back(i);
            dfs(x + 1, ans + a[i], a[i], i);
            b[i] = 0;
            d.emplace_back();
        }
    }
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    dfs(0, 0, -1, 1);
    cout << cnt;
    return 0;
}