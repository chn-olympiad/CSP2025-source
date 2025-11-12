#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+10;

ll n, a[N], k, f[N];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    f[0] = 0;
    for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
    for (int i = 1; i <= n; i++){
        if (a[i]==k) f[i] = f[i-1]+1;
        else{
            ll sum = a[i];
            ll j = i-1;
            while (j>=1&&sum!=k&&f[j]==f[i-1]){
                sum^=a[j];
                j--;
            }
            if (sum==k) f[i] = max(f[j]+1,f[i-1]);
            else f[i] = f[i-1];
        }
    }
    cout << f[n];
    return 0;
}
