#include <bits/stdc++.h>
using namespace std;
//unique XINGZHI! CESHI DIAN 1-3 15-20!
int n, a[5005];
long long ans;
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    //for CESHI DIAN 1-3
    if (n < 3){
        printf("0");
    }else if (n == 3){
        printf("1");
    }else{
        sort(a+1, a+n+1);
        //for CESHI DIAN 15-20
        unsigned long long x;
        if (a[n] == 1){
            //ans = C(n,3) + C(n,4) + ... + C(n,n)
            //C(n,k) = C(n,n-k)
            for (int k = 3; k <= n; k++){
                for (int i = 0; i < k; i++){
                    x *= n-i;
                }
                for (int i = 1; i <= k; i ++){
                    x /= i;
                }
                x %= 998244353;
                ans += x;
                ans %= 998244353;
            }
            cout << ans;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
