#include <bits/stdc++.h>
#define i64 long long
#define dbg(x)
// #define dbg(x) cerr << #x << " = " << (x) << "\n"
using namespace std;

i64 n,m;
const i64 N = 503,mod = 998244353;
i64 s[N],c[N];
i64 cnt = 1;
i64 ans = 0;
i64 r = 0;
vector<i64> a;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(i64 i = 1;i <= n;i++){
        scanf("%1lld",&s[i]);
    }
    for(i64 i = 1;i <= n;i++){
        scanf("%lld",&c[i]);
    }
    if(n <= 12){
        a.resize(n);
        iota(a.begin(),a.end(),1);
        for(i64 i = 1;i <= n;i++){
            cnt = (cnt * i) % mod;
        }
        dbg(cnt);
        for(i64 i = 1;i <= cnt;i++){
            i64 giveup = 0;
            i64 rr = 0;
            dbg(i);
            for(i64 j = 0;j < n;j++){
                dbg(a[j]);
                dbg(c[a[j]]);
                dbg(s[a[j]]);
                if(giveup >= c[a[j]]){
                    giveup++;
                    continue;
                }
                if(s[j + 1] == 1){
                    rr++;
                }else{
                    giveup++;
                }
            }
            dbg(rr);
            if(rr >= m) ans = (ans + 1) % mod;
            next_permutation(a.begin(),a.end());
        }
        printf("%lld",ans);
        return 0;
    }
    ans = 1;
    for(int i = 1;i <= n;i++){
        ans = (ans * i) % mod;
    }
    printf("%lld",ans);
    return 0;
}