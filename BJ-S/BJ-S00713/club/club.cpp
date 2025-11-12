#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
#define int long long
struct stu {
    int x, y, z, id;
};
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        stu a[N];
        vector<int> b, c, d;
        for(int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y >> a[i].z;
            a[i].id = i;
            int maxn = max({a[i].x, a[i].y, a[i].z});
            if(maxn == a[i].x) b.push_back(i);
            else if(maxn == a[i].y) c.push_back(i);
            else if(maxn == a[i].z) d.push_back(i);
        }
        int o = (int)b.size() - n / 2;
        int p = (int)c.size() - n / 2;
        int q = (int)d.size() - n / 2;
        while(o > 0 || p > 0 || q > 0) {
            if(o > 0) {
                int minn = -1;
                int pos = 0, pos2 = 0;
                int cnt = 0, s = 0;
                for(int x : b) {
                    if(x == -1e9) {
                        cnt++;
                        continue;
                    }
                    if(a[x].y > minn) {
                        pos = a[x].id;
                        pos2 = 2;
                        s = cnt;
                        minn = a[x].y;
                    }
                    if(a[x].z > minn) {
                        pos = a[x].id;
                        pos2 = 3;
                        s = cnt;
                        minn = a[x].z;
                    }
                    cnt++;
                }
                if(pos2 == 2) {
                    p++;
                    c.push_back(pos);
                } else if(pos2 == 3) {
                    q++;
                    d.push_back(pos);
                }
                o--;
                b[s] = -1e9;
            }
            if(p > 0) {
                int minn = -1;
                int pos = 0, pos2 = 0;
                int cnt = 0, s = 0;
                for(int y : c) {
                    if(y == -1e9) {
                        cnt++;
                        continue;
                    }
                    if(a[y].x > minn) {
                        pos = a[y].id;
                        pos2 = 1;
                        s = cnt;
                        minn = a[y].x;
                    }
                    if(a[y].z > minn) {
                        pos = a[y].id;
                        pos2 = 3;
                        s = cnt;
                        minn = a[y].z;
                    }
                    cnt++;
                }
                if(pos2 == 1) {
                    o++;
                    b.push_back(pos);
                } else if(pos2 == 3) {
                    q++;
                    d.push_back(pos);
                }
                p--;
                c[s] = -1e9;
            }
            if(q > 0) {
                int minn = -1;
                int pos = 0, pos2 = 0;
                int cnt = 0, s = 0;
                for(int z : d) {
                    if(z == -1e9) {
                        cnt++;
                        continue;
                    }
                    if(a[z].x > minn) {
                        pos = a[z].id;
                        pos2 = 1;
                        s = cnt;
                        minn = a[z].x;
                    }
                    if(a[z].y > minn) {
                        pos = a[z].id;
                        pos2 = 2;
                        s = cnt;
                        minn = a[z].y;
                    }
                    cnt++;
                }
                if(pos2 == 2) {
                    p++;
                    c.push_back(pos);
                } else if(pos2 == 1) {
                    o++;
                    b.push_back(pos);
                }
                q--;
                d[s] = -1e9;
            }
        }
        int ans = 0;
        for(auto x : b) {
            if(x != -1e9) ans += a[x].x;
        }
        for(auto x : c) {
            if(x != -1e9) ans += a[x].y;
        }
        for(auto x : d) {
           if(x != -1e9) ans += a[x].z;
        }
        cout << ans << "\n";
    }
    return 0;
}
