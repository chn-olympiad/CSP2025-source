#include <bits/stdc++.h>
#define max3(a,b,c) max(a,max(b,c))
using namespace std;
typedef long long ll;
const int N = 205;
const int M = 1e5+5;
ll n,t;
ll f[N][N][N];
ll f2[N][N];
struct node{
    ll d[4];
}a[M];
ll a1,a2,a3;
ll cnt = 0;
void init(){
    n = 0;
    for(ll i = 0; i < N; ++i){
        for(ll j = 0; j < N; ++j){
                f2[i][j] = 0;
            for(ll k = 0; k < N; ++k){
                f[i][j][k] = 0;
            }
        }
    }
    for(ll i = 0; i < M; ++i) a[i].d[0] = a[i].d[1] = a[i].d[2] = a[i].d[3] = 0;
    cnt = 0;
    a1 = a2 = a3 = 0;
}

bool cmp(node x,node y){
    if(x.d[1] != y.d[1]) return x.d[1] > y.d[1];
    return x.d[2] > y.d[2];
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        init();
        scanf("%lld",&n);

        for(int i = 1; i <= n; ++i){
            scanf("%lld%lld%lld",&a[i].d[1],&a[i].d[2],&a[i].d[3]);
            a1 = max(a[i].d[1],a1);
            a2 = max(a[i].d[2],a2);
            a3 = max(a[i].d[3],a3);
        }

        if(n <= 30){
            for(int i = 1; i <= n; ++i){
                for(int j = n/2; j >= 0; --j){
                    for(int k = n/2; k >= 0; --k){
                        for(int p = n/2; p >= 0; --p){
                            ll res1 = 0,res2 = 0,res3 = 0;
                            if(j >= 1) res1 = f[j-1][k][p] + a[i].d[1];
                            if(k >= 1) res2 = f[j][k-1][p] + a[i].d[2];
                            if(p >= 1) res3 = f[j][k][p-1] + a[i].d[3];
                            f[j][k][p] = max3(res1,res2,res3);
                            cnt = max(f[j][k][p],cnt);
                        }
                    }
                }
            }
        }

        else if(a2 == 0 && a3 == 0){
            sort(a+1,a+1+n,cmp);
            for(int i = 1; i <= n/2; ++i){
                cnt += a[i].d[1];
            }
        }

        else if(a2 != 0 && a3 == 0){
            //sort(a+1,a+1+n,cmp);
            for(int i = 1; i <= n; ++i){
                for(int j = n/2; j >= 0; --j){
                    for(int k = n/2; k >= 0; --k){
                            ll res1 = 0,res2 = 0;
                            if(j >= 1) res1 = f2[j-1][k] + a[i].d[1];
                            if(k >= 1) res2 = f2[j][k-1] + a[i].d[2];
                            f2[j][k] = max(res1,res2);
                            cnt = max(f2[j][k],cnt);
                        }
                    }
                }
            }
           printf("%lld\n",cnt);
        }

    return 0;
}
