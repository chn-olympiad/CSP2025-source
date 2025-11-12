#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5005;
int n, a[maxn];
set<int> st;
void dfs(int it, int len, int ma, int num) {
    if (it == n + 1) {
        if (len < ma * 2) return;
        if (num < 3) return;
        st.insert(len);
        return;
    }
    dfs(it + 1, len + a[it], max(ma, a[it]), num + 1);
    dfs(it + 1, len, ma, num);
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, 0, 0, 0);
    cout << st.size();
    return 0;
}
