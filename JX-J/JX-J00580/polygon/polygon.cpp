#include<bits/stdc++.h>
using namespace std;

int n,a[5003],k[5003];
long long ans;

int find_max(int r) {
    int res = 0;
    for (int i = 0;i <= r;i++) {
        if (k[i] > res) res = k[i];
    }
    return res;
}

int sum(int r) {
    int res = 0;
    for (int i = 0;i <= r;i++) {
        res += k[i];
    }
    return res;
}

void dfs(int c,int last,int l) {
    if (c >= l - 1) {
        int m = find_max(c),s = sum(c);
        if (s > 2 * m) {
            ++ans;
        }
        return;
    }
    for (int i = last + 1;i < n;i++) {
        k[c + 1] = a[i];
        dfs(c + 1,i,l);
    }
}

int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int l = 3;l <= n;l++) {
        dfs(-1,-1,l);
    }
    cout << ans;
    return 0;
}
