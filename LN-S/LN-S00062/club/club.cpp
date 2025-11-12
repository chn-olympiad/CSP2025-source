#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define read int

inline read rd() {
    int x = 0, f = 1, ch = getchar();
    for(; !isdigit(ch); ch = getchar()) {
        if(ch == '-') {
            f = -1;
        }
    }
    for(; isdigit(ch); ch = getchar()) {
        x = (x * 10) + (ch ^ 48);
    }
    return f * x;
}



const int N = 1e5 + 10;

struct member {
    int a[5];
}aa[N];

int t;

int f[N][5];

bool cmp(member x, member y) {
    return max({x.a[1], x.a[2], x.a[3]}) > max({y.a[1], y.a[2], y.a[3]});
}

bool cmp1(member x, member y) {
    return x.a[1] > y.a[1];
}


int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    t = rd();
    while (t--) {
        int n = rd();
        bool ff = 0;
        for(int i=1; i<=n; i++) {
            aa[i].a[1] = rd();
            aa[i].a[2] = rd();
            aa[i].a[3] = rd();
            if(aa[i].a[2] != 0 || aa[i].a[3] != 0) {
                ff = 1;
            }
        }
        if(!ff) {
            sort(aa + 1, aa + 1 + n, cmp1);
            int ans = 0;
            for(int i=1; i<=n/2; i++) {
                ans += aa[i].a[1];
            }
            cout<< ans << '\n';
        }
        else {
            sort(aa + 1, aa + 1 + n, cmp);
            int cnt[4] = {};
            for(int i=1; i<=n; i++) {
                int maxx = -1;
                if(f[i-1][1] > f[i-1][2] && f[i-1][1] > f[i-1][3]) {
                    maxx = 1;
                }
                else if(f[i-1][2] > f[i-1][1] && f[i-1][2] > f[i-1][3]) {
                    maxx = 2;
                }
                else {
                    maxx = 3;
                }

                cnt[maxx] ++;

                if(cnt[maxx] > n / 2) {
                    f[i][maxx] = -1e9;
                    if(f[i-1][1] > f[i-1][2] && f[i-1][1] > f[i-1][3]) {
                        maxx = 1;
                    }
                    else if(f[i-1][2] > f[i-1][1] && f[i-1][2] > f[i-1][3]) {
                        maxx = 2;
                    }
                    else {
                        maxx = 3;
                    }

                    cnt[maxx] ++;
                    if(cnt[maxx] > n / 2) {
                        f[i][maxx] = -1e9;
                        if(f[i-1][1] > f[i-1][2] && f[i-1][1] > f[i-1][3]) {
                            maxx = 1;
                        }
                        else if(f[i-1][2] > f[i-1][1] && f[i-1][2] > f[i-1][3]) {
                            maxx = 2;
                        }
                        else {
                            maxx = 3;
                        }

                        cnt[maxx] ++;
                    }
                }
                
                for(int j=1; j<=3; j++) {
                    f[i][j] = f[i-1][maxx] + aa[i].a[j];
                }

            }
            cout<< max({f[n][1], f[n][2], f[n][3]}) << '\n';
        }
    }



    return 0;
}

// LN-S00062

/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


road.cpp:24:12: warning: ignoring return value of ‘FILE* freopen(const char*, const char*, FILE*)’, declared with attribute warn_unused_result [-Wunused-result]
   24 |     freopen("road.in", "r", stdin);
      |     ~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~
road.cpp:25:12: warning: ignoring return value of ‘FILE* freopen(const char*, const char*, FILE*)’, declared with attribute warn_unused_result [-Wunused-result]
   25 |     freopen("road.out", "w", stdout);
      |     ~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~


*/
