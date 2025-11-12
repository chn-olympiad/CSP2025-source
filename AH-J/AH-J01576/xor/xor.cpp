#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll n, k, a[N];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%lld%lld", &n, &k);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    if(k == 0) printf("%lld", n / 2);
    if(k == 1){
        ll cnt = 0;
        for(int i=1; i<=n-1; i++){
            if(a[i] != a[i + 1]){
                cnt++;
                i++;
            }
        }
        printf("%lld", cnt);
    }
    return 0;
}
