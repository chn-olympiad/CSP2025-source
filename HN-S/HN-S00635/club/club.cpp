#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100005

int r[MAXN][3];
int n;
bool vis[MAXN];

int search(int a, int b, int c) {
    int ans = 0;

    if ( a == 0 && b == 0 && c == 0 )
        return 0;

    for (int i = 1;i<=n;i++) {
        if (vis[i]) continue;

        vis[i] = true;

        int t1 = 0, t2 = 0, t3 = 0;

        if (a >= 1)
            t1 = search(a-1,b,c) + r[i][0];
        if (b >= 1)
            t2 = search(a,b-1,c) + r[i][1];
        if (c >= 1)
            t3 = search(a,b,c-1) + r[i][2];

        int sub = max(max(t1,t2),t3);
        if (ans < sub)
            ans = sub;
        vis[i] = false;
    }

    return ans;
}

auto main() -> int {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);

        for (int i=1;i<=n;i++)
            vis[i] = false;

        for (auto i=1; i <= n; i++) {
            int a,b,c;
            scanf("%d %d %d", &a, &b, &c);
            r[i][0] = a;
            r[i][1] = b;
            r[i][2] = c;
        }

        printf("%d\n", search(n/2,n/2,n/2));
    }

    return 0;
}
