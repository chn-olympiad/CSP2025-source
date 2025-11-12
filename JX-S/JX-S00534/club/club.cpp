#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int T = 1;
int n;
struct note {
    int x, y, z;
} a[N];
struct club1 {
    int v, id;
    friend bool operator < (club1 c, club1 d) {
        return a[c.id].x - max(a[c.id].y, a[c.id].z) > a[d.id].x - max(a[d.id].y, a[d.id].z);
    }
};
struct club2 {
    int v, id;
    friend bool operator < (club2 c, club2 d) {
        return a[c.id].y - max(a[c.id].x, a[c.id].z) > a[d.id].y - max(a[d.id].x, a[d.id].z);
    }
};
struct club3 {
    int v, id;
    friend bool operator < (club3 c, club3 d) {
        return a[c.id].z - max(a[c.id].y, a[c.id].x) > a[d.id].z - max(a[d.id].y, a[d.id].x);
    }
};
priority_queue<club1> q1;
priority_queue<club2> q2;
priority_queue<club3> q3;
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
            int m = max({a[i].x, a[i].y, a[i].z});
            if(m == a[i].x) {
                if(q1.size() < n / 2) {
                    q1.push({a[i].x, i});
                } else {
                    club1 tmp = q1.top();
                    if(max(a[tmp.id].y, a[tmp.id].z) + m - tmp.v > max(a[i].y, a[i].z)) {
                        q1.pop();
                        q1.push({m, i});
                        if(max(a[tmp.id].y, a[tmp.id].z) == a[tmp.id].y) {
                            q2.push({a[tmp.id].y, tmp.id});
                        } else {
                            q3.push({a[tmp.id].z, tmp.id});
                        }
                    } else {
                        if(max(a[i].y, a[i].z) == a[i].y) {
                            q2.push({a[i].y, i});
                        } else {
                            q3.push({a[i].z, i});
                        }
                    }
                }
            } else if(m == a[i].y) {
                if(q2.size() < n / 2) {
                    q2.push({a[i].y, i});
                } else {
                    club2 tmp = q2.top();
                    if(max(a[tmp.id].x, a[tmp.id].z) + m - tmp.v > max(a[i].x, a[i].z)) {
                        q2.pop();
                        q2.push({m, i});
                        if(max(a[tmp.id].x, a[tmp.id].z) == a[tmp.id].x) {
                            q1.push({a[tmp.id].x, tmp.id});
                        } else {
                            q3.push({a[tmp.id].z, tmp.id});
                        }
                    } else {
                        if(max(a[i].x, a[i].z) == a[i].x) {
                            q1.push({a[i].x, i});
                        } else {
                            q3.push({a[i].z, i});
                        }
                    }
                }
            } else {
                if(q3.size() < n / 2) {
                    q3.push({a[i].z, i});
                } else {
                    club3 tmp = q3.top();
                    if(max(a[tmp.id].x, a[tmp.id].y) + m - tmp.v > max(a[i].x, a[i].y)) {
                        q3.pop();
                        q3.push({m, i});
                        if(max(a[tmp.id].x, a[tmp.id].y) == a[tmp.id].x) {
                            q1.push({a[tmp.id].x, tmp.id});
                        } else {
                            q2.push({a[tmp.id].y, tmp.id});
                        }
                    } else {
                        if(max(a[i].x, a[i].y) == a[i].x) {
                            q1.push({a[i].x, i});
                        } else {
                            q2.push({a[i].y, i});
                        }
                    }
                }
            }
             //printf("%zd %zd %zd\n", q1.size(), q2.size(), q3.size());
        }
        int ans = 0;
        while(!q1.empty()) {
            ans += q1.top().v;
            q1.pop();
        }
        while(!q2.empty()) {
            ans += q2.top().v;
            q2.pop();
        }
        while(!q3.empty()) {
            ans += q3.top().v;
            q3.pop();
        }
        printf("%d\n", ans);
    }
}
/*
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
