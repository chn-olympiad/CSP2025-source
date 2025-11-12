#include<bits/stdc++.h>
using namespace std;

const long long P = 998244353;
int n, m, s[1001], p[1001];

int main (  ) {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for(int i = 1 ;i <= n ;i++){
        printf("%d", &p[i]);
    }
    sort(p + 1, p + n + 1);
    if(m == 1){
        int l = strlen(s + 1), j = 0;
        for(int i = 1; i <= l; i++){
            if(s[i] == '1'){
                j = i;
            }
        }
        if(!j || p[1] < j){
            printf("0\n");
            return 0;
        }
        long long ans = 0;
        if(p[n] >= j){

            for(int i = 1; i <= n; i++){
                ans *= 1LL * i;
                ans %= P;
            }
            printf("%lld\n", ans);
        }
        else {
            int k = 0;
            for(int i = 1 ;i <= n ;i++){
                if(p[i] >= j){
                    k = i;
                }
            }
            for(int i = 1; i <= k; i++){
                ans *= 1LL * i;
                ans %= P;
            }
            printf("%lld\n", ans);
        }
        return 0;
    }
    return 0;
}
