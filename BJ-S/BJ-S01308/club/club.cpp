#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1e5 + 10;
bool vis[maxn];
bool vis2[maxn];
int ans2;
struct Node{
    int a, b, c;
}p[maxn];
struct Node2{
    int dif, id;
}d[maxn];
struct Node3{
    int l, r, g, id;
}f[3 * maxn];
bool cmp(Node x, Node y){
    return x.a > y.a;
}
bool cmp2(Node2 x, Node2 y){
    return x.dif > y.dif;
}
bool cmp3(Node3 x, Node3 y){
    return x.g > y.g;
}
void dfs(int num1, int num2, int num3, int sum, int n){
    int tot = num1 + num2 + num3;
    if(tot == n){
        ans2 = max(ans2, sum);
        return;
    }
    int x = tot + 1;
    if(num1 < n / 2){
        dfs(num1 + 1, num2, num3, sum + p[x].a, n);
    }
    if(num2 < n / 2){
        dfs(num1, num2 + 1, num3, sum + p[x].b, n);
    }
    if(num3 < n / 2){
        dfs(num1, num2, num3 + 1, sum + p[x].c, n);
    }
    return;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        memset(vis, 0, sizeof(vis));
        memset(vis2, 0, sizeof(vis));
        int n; cin >> n;
        bool flaga = 1, flagb = 1;
        for(int i = 1; i <= n; i++){
            cin >> p[i].a >> p[i].b >> p[i].c;
            if(p[i].b != 0 || p[i].c != 0) flaga = 0;
            if(p[i].c != 0) flagb = 0;
        }
        //cout << flaga << " " << flagb << "\n";
        if(flaga){
            sort(p + 1, p + n + 1, cmp);
            int ans = 0;
            for(int i = 1; i <= n / 2; i++) ans += p[i].a;
            cout << ans << "\n";
        } else if(flagb){
            for(int i = 1; i <= n; i++){
                d[i].id = i;
                d[i].dif = p[i].a - p[i].b;
            }
            sort(d + 1, d + n + 1, cmp2);
            int ans = 0;
            for(int i = 1; i <= n / 2; i++){
                ans += p[d[i].id].a;
            }
            for(int i = n / 2 + 1; i <= n; i++){
                ans += p[d[i].id].b;
            }
            cout << ans << "\n";
        } else if(n <= 10){
            ans2 = 0;
            dfs(1, 0, 0, p[1].a, n);
            dfs(0, 1, 0, p[1].b, n);
            dfs(0, 0, 1, p[1].c, n);
            cout << ans2 << "\n";
        } else{
            int cnt = 0;
            //l > r
            for(int i = 1; i <= n; i++){
                f[++cnt].g = p[i].a - p[i].b;
                f[cnt].l = 1;
                f[cnt].r = 2;
                f[cnt].id = i;
                if(f[cnt].g < 0){
                    f[cnt].g = f[cnt].g * -1;
                    swap(f[cnt].l, f[cnt].r);
                }
                f[++cnt].g = p[i].b - p[i].c;
                f[cnt].l = 2;
                f[cnt].r = 3;
                f[cnt].id = i;
                if(f[cnt].g < 0){
                    f[cnt].g = f[cnt].g * -1;
                    swap(f[cnt].l, f[cnt].r);
                }
                f[++cnt].g = p[i].a - p[i].c;
                f[cnt].l = 1;
                f[cnt].r = 3;
                f[cnt].id = i;
                if(f[cnt].g < 0){
                    f[cnt].g = f[cnt].g * -1;
                    swap(f[cnt].l, f[cnt].r);
                }
            }
            sort(f + 1, f + cnt + 1, cmp3);
            int num1 = 0, num2 = 0, num3 = 0;
            int ans = 0;
            for(int i = 1; i <= cnt; i++){
                if(!vis[f[i].id]){
                    if(f[i].l == 1){
                        if(num1 < n / 2){
                            vis[f[i].id] = 1;
                            num1++;
                            ans += p[f[i].id].a;
                            //cout << ans << " 1 \n";
                        }
                    }
                    if(f[i].l == 2){
                        if(num2 < n / 2){
                            vis[f[i].id] = 1;
                            num2++;
                            ans += p[f[i].id].b;
                            //cout << ans << " 2 \n";
                        }
                    }
                    if(f[i].l == 3){
                        if(num3 < n / 2){
                            vis[f[i].id] = 1;
                            num3++;
                            ans += p[f[i].id].c;
                            //cout << ans << " 3 \n";
                        }
                    }
                }
            }
            //cout << ans << "\n";
            int mx1 = 0, mx2 = 0, mx3 = 0, pre1 = 0, pre2 = 0, pre3 = 0;
            for(int i = 1; i <= n; i++){
                if(p[i].a > mx1 && !vis2[i]){
                    vis2[i] = 1;
                    mx1 = vis2[i];
                    vis2[pre1] = 0;
                    pre1 = i;
                }
            }
            for(int i = 1; i <= n; i++){
                if(p[i].b > mx2 && !vis2[i]){
                    vis2[i] = 1;
                    mx2 = vis2[i];
                    vis2[pre2] = 0;
                    pre2 = i;
                }
            }
            for(int i = 1; i <= n; i++){
                if(p[i].c > mx3){
                    vis2[i] = 1;
                    mx3 = vis2[i];
                    vis2[pre3] = 0;
                    pre3 = i;
                }
            }
            int ans3 = mx1 + mx2 + mx3;
            int mx4 = 0;
            for(int i = 1; i <= n; i++){
                if(!vis[i]){
                    mx4 = max(mx4, p[i].a);
                    mx4 = max(mx4, p[i].b);
                    mx4 = max(mx4, p[i].c);
                }
            }
            ans3 += mx4;
            cout << max(ans, ans3) << "\n";
        }
    }
    return 0;
}
