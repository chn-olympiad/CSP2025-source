#include <cstdio>
#include <algorithm>

using namespace std;

struct member {
    int as[3];
} a[500];

int n;
int ans;

int gs[500];
int n1, n2, n3;
void ddfs(int pos) {
    if (n1 > n/2 || n2 > n/2 || n3 > n/2) return;
    if (pos == n && n1 <= n/2 && n2 <= n/2 && n3 <= n/2) {
        int cnt = 0;
        for (int i = 0;i < n;++i) {
            cnt += a[i].as[gs[i] - 1];
        }
        if (cnt > ans) ans = cnt;
        return;
    }
    n1++;
    gs[pos] = 1;
    ddfs(pos + 1);
    n1--;

    n2++;
    gs[pos] = 2;
    ddfs(pos + 1);
    n2--;

    n3++;
    gs[pos] = 3;
    ddfs(pos + 1);
    n3--;
}

void kmain() {
    n1 = 0;
    n2 = 0;
    n3 = 0;
    ans = 0;
    scanf("%d", &n);
    for (int i = 0;i < n;++i) {
        scanf("%d %d %d", &a[i].as[0], &a[i].as[1], &a[i].as[2]);
    }
    ddfs(0);
    printf("%d\n", ans);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        kmain();
    }
}