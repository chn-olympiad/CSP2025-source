#include<bits/stdc++.h>
using namespace std;

int n;
const int maxn = 1e5 + 5;
int a[maxn][3];
int op[maxn];
int maxx;

int half;
int delta[maxn];
int tot;

int ans;
int cnt[3];

void motify(int opt, int e1, int e2) {
    tot = 0;
    for(int i = 1; i <= n; i ++) {
        if(op[i] ^ opt) continue;
        delta[++ tot] = (a[i][opt] - max(a[i][e1], a[i][e2]));
    }
    sort(delta + 1, delta + tot + 1);
    for(int i = 1; i <= (cnt[opt] - half); i ++) ans -= delta[i];
}

int Solve() {
    scanf("%d", &n);
    cnt[0] = cnt[1] = cnt[2] = 0;
    ans = 0;
    for(int i = 1; i <= n; i ++) {
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
        maxx = max(max(a[i][0], a[i][1]), a[i][2]);
        ans += maxx;
        if(maxx == a[i][0]) {
            op[i] = 0;
            cnt[0] ++;
        }
        else if(maxx == a[i][1]) {
            cnt[1] ++;
            op[i] = 1;
        }
        else {
            cnt[2] ++;
            op[i] = 2;
        }
    }
    half = (n >> 1);
    if(cnt[0] > half) {
        motify(0, 1, 2);
    }
    else if(cnt[1] > half) {
        motify(1, 2, 0);
    }
    else if(cnt[2] > half) {
        motify(2, 0, 1);
    }
    return ans;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t --) printf("%d\n", Solve());
    return 0;
}
