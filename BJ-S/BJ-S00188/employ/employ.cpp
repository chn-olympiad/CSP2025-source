#include <bits/stdc++.h>
using namespace std;
#define MAXN 505
int c[MAXN];
int p[MAXN];
int tong[MAXN];
const long long mod = 998244353;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m; string s; scanf("%d%d",&n,&m); cin >> s; s = " " + s;
    for(int i = 1; i <= n; i++) scanf("%d",&c[i]);
    for(int i = 1; i <= n; i++) p[i] = i;
    if(n <= 10){
        long long ans = 0;
        do{
            int num = 0;
            int shu = 0;
            for(int i = 1; i <= n; i++){
                if(shu >= c[p[i]]){shu++; continue;}
                if(s[i] == '1') num++;
                else shu++;
            }
            if(num >= m) ans++;
            //cerr << num << " ";
        }while(next_permutation(p + 1,p + n + 1));
        printf("%lld\n",ans % 998244353);
    }else if(n == m){
        bool ok = 1;
        for(int i = 1; i <= n; i++) if(s[i] == '0') ok = 0;
        if(ok) printf("1\n");
        else printf("0\n");
    }else if(m == 1){
        for(int i = 1; i <= n; i++) tong[c[i]]++;
        for(int i = 1; i <= n; i++) tong[i] = tong[i-1] + tong[i];
        long long ansmax = 1;
        for(int i = 1; i <= n; i++) ansmax = (ansmax * i) % mod;
        long long ans = 1;
        int geshu = 0;
        for(int i = 1; i <= n; i++){
            if(s[i] == '1'){
                geshu++;
                if(tong[i-1] < geshu){ans = ansmax; break;}
                ans = ans * (tong[i-1] - geshu + 1) % mod;
            }
        }
        for(int i = 1; i <= n - geshu; i++) ans = (ans * i) % mod;
        printf("%lld\n",(ansmax - ans + mod) % mod);
    }
    
    return 0;
}