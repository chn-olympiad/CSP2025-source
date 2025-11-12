#include <bits/stdc++.h>
#define int long long
#define rg register
using namespace std;
const int MAXN = 1000 + 5;
inline void fre()
{
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    return ;
}
int p[MAXN];
int n, k, a[MAXN];
int yz[260][260];
int dis[9] = {0, 1, 2, 4, 8, 16, 32, 64, 128};
int ans = 0, up = 0;
int dp[MAXN][MAXN];
bool A = true;
inline void slove0(int step, int ks)
{
    if (step > n) return ;
    if (a[step] == 1) ks++;
    if(ks >= 2){ks -= 2; ans++;}
    slove0(step + 1, ks);
    return ;
}
inline int maxx(int a, int b){
    if (a > b) return a;
    return b;
}
inline void hitform()
{
    for (rg int i = 0; i <= 255; i++)
    {
        for (rg int j = i + 1; j <= 255; j++)
        {
            int a1 = i, a2 = j;
//            cout <<a1<<" "<<a2<<endl;
            for (rg int k = 8; k >= 1; k--)
            {
        //        cout <<  k;
                if (a2 < dis[k]) continue;
  //              cout <<  k;
                if (a1 >= dis[k])
                {
                    a2 -= dis[k];
                    a1 -= dis[k];
                    continue;
                }
    //            cout <<  k<<endl;
                a2 -= dis[k];
                if (a2 < a1)
                {
                    int tmp = a1;
                    a1 = a2; a2 = tmp;
                }
    //            cout << a1<<" "<<a2<<endl;
                yz[i][j] = dis[k] + yz[a1][a2];
                break;
            }
            yz[j][i] = yz[i][j];
        }
    }
    return ;
}
int kl = 0;
inline void f(int step, int sum)
{
    if (step > n) return ;
    sum = yz[sum][a[step]];
    if (sum == k){p[kl] = step; return ;};
    f(step + 1, sum);
    return ;
}
inline void goi(int step, int sum)
{
    ans = maxx(ans, sum);
    for (rg int i = step + 1; i <= n; i++){
        if (!p[i]) continue;
        goi(p[i], sum + 1);
    }
    return ;
}
signed main()
{
    fre();
    hitform();
    /*for (rg int i = 1; i <= 10; i++)
    {
        for (rg int j = 1; j <= 10; j++)
        {
            printf ("%lld ", yz[i][j]);
        }
        printf ("\n");
    }*/
    scanf ("%lld%lld", &n, &k);
    for (rg int i = 1; i <= n; i++)
    {
        scanf ("%lld", &a[i]);
        if (a[i] != 1) A = false;
    }
    if (k == 0 && A){slove0(1, 0); printf ("%lld\n", ans);return 0;};
    for (rg int i = 1; i <= n; i++)
    {
        kl = i;
        f(i, 0);
    }
    for (rg int i = 1; i <= n; i++){
        if (p[i] == 0) continue;
        goi(p[i], 1);
    }
    printf ("%lld\n", ans);
    return 0;
}
