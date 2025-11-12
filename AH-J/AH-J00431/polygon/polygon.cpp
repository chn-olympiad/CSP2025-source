#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 5010;
const int M = 998244353;

int a[N];
long long cnt = 0;
bool vis[N];

void dfs(int now, int sum, int mx) {
    if (now > n) {
        if (sum > mx * 2) {
            cnt++;
            cnt %= M;
        }
        return;
    }
    dfs(now+1, sum+a[now], max(mx, a[now]));

    dfs(now+1, sum, mx);
}

map<pair<pair<int, long long>, int>, long long> mem;
long long dfs2(int now, long long sum, int mx) {
    if (now > n) {
        if (sum > mx * 2) {
            return 1;
        }
        return 0;
    }
    if (mem.find({{now, sum}, mx}) != mem.end()) {
        return mem[{{now, sum}, mx}];
    } else {
        mem[{{now, sum}, mx}] = (dfs2(now+1, sum+a[now], max(mx, a[now])) + dfs2(now+1, sum, mx)) % M;
        return mem[{{now, sum}, mx}];
    }
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    if (n <= 20) {
        dfs(1, 0, 0);
        printf("%lld", cnt);
    } else {
        printf("%lld", dfs2(1, 0, 0));
    }
    return 0;
}

// Ah, 50pts is good.
// Problem creater is a little good.
// I can add a array named memory.
// I can try.
// ...not a good code, I think it can't ac.
// However, I maybe have 1=
