#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
int a[5005];

bool p(vector<int> num) {
    if (num.size() < 3) return false;
    int maxn = -1, sum = 0;
    for (int i = 0; i < num.size(); i++) {
        sum += num[i];
        maxn = max(maxn, num[i]);
    }
    return sum > 2 * maxn;
}


void dfs(vector<int> num, int j) {
    if (p(num) && num.size() <= n) {
        ans++;
    }
    if (num.size() > n && j >= n) return;
    for (int i = j; i < n; ){
        num.push_back(a[i]);
        dfs(num, ++i);
        num.pop_back();
    }
}


int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> num;
    dfs(num, 0);
    cout << ans % 998244535;
    return 0;
}
