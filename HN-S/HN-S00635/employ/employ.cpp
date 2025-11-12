#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

using LL = long long;

const LL MODV = 998244353;

const int MAXN = 500;

int n, m;
int c[MAXN];
bool s[MAXN];
bool vis[MAXN];
LL ans;

auto calc(int id, LL count, LL h) {
    if (id == n-1) {
        if (h + 1 < m) {
            return;
        }
        if (h+1 == m && !s[id])  {
            return;
        }
        for (int i=0;i<n;i++) {
            if (vis[i]) continue;
            if (c[i] <= count && h+1 == m) continue;
            //printf("%d = %d(%d %d %d)\n", id,i,c[i],h,m);
            ans ++;
            ans %= MODV;
        }
    }
    for (int i=0;i<n;i++) {
        if (vis[i]) continue;
        vis[i] = true;

        int new_count = count;
        int new_h = h;
        if (c[i] <= count || !s[i])
            new_count++;
        else
            new_h++;
        //if (id == 2)printf("%d = %d(%d %d)\n", id, i, new_count, new_h);
        calc(id+1, new_count, new_h);
        //if (id == 2)printf("%d\n", id);

        vis[i] = false;
    }
}

auto main() -> int {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    scanf("%d %d", &n, &m);
    getchar();

    string str;
    getline(cin, str);
    for (int i=0;i<n;i++) {
        char tmp = str[i];
        s[i] = tmp == '1';
    }

    for (int i=0;i<n;i++) {
        scanf("%d", c + i);
    }

    calc(0,0ll,0ll);
    printf("%lld\n", ans % MODV);

    return 0;
}
