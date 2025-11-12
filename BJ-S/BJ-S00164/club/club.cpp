#include <bits/stdc++.h>
using namespace std;
int t;

struct node{
    long long a, b, c, d;
}a[100005];
long long ii = 0;
long long ans = 0, n, sum = 0;
void dfs(int x, int y, int z, long long cnt,long long xx){
    if(x+y+z > n){
        if(x <= n/2 && y <= n/2 && z <= n/2){
            ans = max(ans, cnt);
        }
        return;
    }
    dfs(x+1, y, z, cnt + a[xx].a, xx+1);
    dfs(x, y+1, z, cnt + a[xx].b, xx+1);
    dfs(x, y, z+1, cnt + a[xx].c, xx+1);
}

bool cmp(node x, node y){
    return x.c >y.c;
}

bool cmp1(node x, node y){
    return x.b > y.b;
}

bool cmp2(node x, node y){
    return x.a > y.a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t --){
        long long dp[100005][5];
        memset(a, 0, sizeof(a));
        cin >> n;
        ans = 0;
        for(int i = 1; i <= n; i ++){
            cin >> a[i].a >> a[i].b >> a[i].c;
        }
        if(n < 30){
            dfs(0, 0, 0, 0,1);
            cout << ans << endl;
        }
        if(n >= 30){
            int fa = 0, fb = 0, fc = 0;
            for(int i = 1; i <= n; i ++){
                fa += a[i].a;
                fb += a[i].b;
                fc += a[i].c;
            }
            long long sum = 0;
            if(fa == 0 && fb == 0){
                sort(a+1, a+1+n, cmp);
                for(int i = 1; i <= n/2; i ++){
                    sum += a[i].c;
                }
            }
            if(fa == 0 && fc == 0){
                sort(a+1, a+1+n, cmp1);
                for(int i = 1; i <= n/2; i ++){
                    sum += a[i].b;
                }
            }
            if(fb == 0 && fc == 0){
                sort(a+1, a+1+n, cmp2);
                for(int i = 1; i <= n/2; i ++){
                    sum += a[i].a;
                }
            }
            dp[1][1] = a[1].a;
            dp[1][2] = a[1].b;
            dp[1][3] = a[1].c;
            int f1 = 0, f2 = 0, f3 = 0;
            if(fa != 0 && fb != 0 || fa!=0 && fb != 0 || fb != 0 && fc != 0){
                long long maxn = -1;
                for(int i = 2; i <= n; i ++){
                    dp[i][1] = max(dp[i-1][2] + a[i].a, dp[i-1][3] + a[i].a);
                    if(f1 < n/2){
                        if(dp[i-1][1] + a[i].a > dp[i][1]){
                            f1 ++;
                            dp[i][1] = a[i].a + dp[i-1][1];
                        }
                    }
                    dp[i][2] = max(dp[i-1][1] + a[i].b, dp[i-1][3] + a[i].b);
                    if(f2 < n/2){
                        if(dp[i-1][2] + a[i].b > dp[i][2]){
                            f2 ++;
                            dp[i][2] = dp[i-1][2] + a[i].b;
                        }
                    }
                    dp[i][3] = max(dp[i-1][1] + a[i].c, dp[i-1][2] + a[i].c);
                    if(f3 < n/2){
                        if(dp[i-1][3] + a[i].c > dp[i][3]){
                            f3 ++;
                            dp[i][3] = dp[i-1][3] + a[i].c;
                        }
                    }
                }
                sum = max(dp[n][1], max(dp[n][2], dp[n][3]));
            }
            cout << sum << endl;
        }

    }
    return 0;
}
