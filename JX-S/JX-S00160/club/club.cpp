#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;
const int N = 1e5 + 5;
struct node {
    int w1, w2, id2, id3;
    inline bool operator < (const node &b) const {return w1 == b.w1 ? w2 < b.w2 : w1 < b.w1;}
    inline bool operator > (const node &b) const {return w1 == b.w1 ? w2 > b.w2 : w1 > b.w1;}
};
priority_queue<node> q[4];
int T, n, m, sum, ans, cnt[4];
int main () {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n), m = n >> 1;
        FOR(i, 1, 3) while (q[i].size()) q[i].pop();       
        ans = cnt[1] = cnt[2] = cnt[3] = 0;
        for (int i = 1, a, b, c, Max, sec, Min, t1, t2, t3; i <= n; i++) {
            scanf("%d%d%d", &a, &b, &c);
            Max = max(a, max(b, c)), Min = min(a, min(b, c));
            if (Max == a) sec = max(b, c);
            if (Max == b) sec = max(a, c);
            if (Max == c) sec = max(a, b);
            if (a == Max) t1 = 1;
            if (b == Max) t1 = 2;
            if (c == Max) t1 = 3;
            if (a == sec) t2 = 1;
            if (b == sec) t2 = 2;
            if (c == sec) t2 = 3;
            t3 = 6 - t1 - t2, ans += Max;
            q[t1].push({sec - Max, Min - sec, t2, t3}), cnt[t1]++;
        }
        FOR(i, 1, 3) while (cnt[i] > m) {
            int x = q[i].top().w1, y = q[i].top().w2, z = q[i].top().id2, d = q[i].top().id3;
            q[i].pop(), ans += x, q[z].push({y, 0, d, 0}), cnt[z]++, cnt[i]--;      
        }          
        printf("%d\n", ans);
    }
    return 0;
}