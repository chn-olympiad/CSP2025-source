#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, t, idx[3];

int ck(int x, int y, int z) {
    if (x >= y && x >= z) {
        return 0;
    }
    if (y > x && y > z) {
        return 1;
    }
    return 2;
}

struct node {
    int b[3];
};
node a[N], b[N], c[N], member[N];

bool cmp(node a, node b) {
    return min(a.b[0] - a.b[1], a.b[0] - a.b[2]) > min(b.b[0] - b.b[1], b.b[0] - b.b[2]);
}
bool cmp1(node a, node b) {
    return min(a.b[1] - a.b[0], a.b[1] - a.b[2]) > min(b.b[1] - b.b[0], b.b[1] - b.b[2]);
}
bool cmp2(node a, node b) {
    return min(a.b[2] - a.b[0], a.b[2] - a.b[1]) > min(b.b[2] - b.b[0], b.b[2] - b.b[1]);
}

void update(int id) {
    if (id == 0) {
        sort(a + 1, a + idx[0] + 1, cmp);
        for (int i = idx[0]; i > n / 2; i--) {
            if (a[i].b[0] - a[i].b[1] < a[i].b[0] - a[i].b[2]) {
                idx[1]++;
                b[idx[1]] = a[i];
                idx[0]--;
            } else {
                idx[2]++;
                c[idx[2]] = a[i];
                idx[0]--;
            }
        }
    } else if (id == 1) {
        sort(b + 1, b + idx[1] + 1, cmp1);
        for (int i = idx[1]; i > n / 2; i--) {
            if (b[i].b[1] - b[i].b[0] < b[i].b[1] - b[i].b[2]) {
                idx[0]++;
                a[idx[0]] = b[i];
                idx[1]--;
            } else {
                idx[2]++;
                c[idx[2]] = b[i];
                idx[1]--;
            }
        }
    } else if (id == 2) {
        sort(c + 1, c + idx[2] + 1, cmp2);
        for (int i = idx[2]; i > n / 2; i--) {
            if (c[i].b[2] - c[i].b[0] < c[i].b[2] - c[i].b[1]) {
                idx[0]++;
                a[idx[0]] = c[i];
                idx[2]--;
            } else {
                idx[1]++;
                b[idx[1]] = c[i];
                idx[2]--;
            }
        }
    }
}

int query() {
    int ans = 0;
    for (int i = 1; i <= idx[0]; i++) {
        ans += a[i].b[0];
    }
    for (int i = 1; i <= idx[1]; i++) {
        ans += b[i].b[1];
    }
    for (int i = 1; i <= idx[2]; i++) {
        ans += c[i].b[2];
    }
    return ans;
}

void init() {
    idx[0] = idx[1] = idx[2] = 0;
}

void solve() {
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &member[i].b[j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int id = ck(member[i].b[0], member[i].b[1], member[i].b[2]);
        idx[id]++;
        if (id == 0) {
            a[idx[id]] = member[i];
        } else if (id == 1) {
            b[idx[id]] = member[i];
        } else {
            c[idx[id]] = member[i];
        }
    }
    int ans = 0;
    if (idx[0] > n / 2) {
        update(0);
    } else if (idx[1] > n / 2) {
        update(1);
    } else if (idx[2] > n / 2) {
        update(2);
    }
    ans = query();
    printf("%d\n", ans);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        solve();
    }

    return 0;
}
