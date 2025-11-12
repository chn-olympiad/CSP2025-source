#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;
const int mod = 998244353;
int n;
int a[N],maxn,sum;
bool flag1,flag2 = 1;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    //12pts + 25pts
    cin >> n;
    if(n == 3) flag1 = 1;
    // if(n <= 10) flag3 = 1;
    for(int i = 1;i <= n;++ i){
        cin >> a[i];
        if(a[i] != 1) flag2 = 0;
        maxn = max(maxn,a[i]);
        sum += a[i];
    }
    if(flag1){
        if(sum > 2 * maxn) printf("1\n");
        else printf("0\n");
        return 0;
    }
    if(flag2){
        int ans = 0,res1 = 2,res2 = n * (n - 1);
        for(int i = 3;i <= n;++ i){
            res1 *= i % mod;
            res2 *= (n - i + 1) % mod;
            ans += res2 / res1;
            ans %= mod;
            // printf("ans : %d\n",ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}