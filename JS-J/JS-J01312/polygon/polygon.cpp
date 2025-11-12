#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
const ll mod = 998244353;
ll n,a[N],sum;
ll f[N],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    f[0] = 1;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i < n;i++){
        sum += a[i];
        for(int j = sum;j >= a[i];j--) f[j] = (f[j]+f[j-a[i]])%mod;
        if(i == 1) continue;
        for(int j = a[i+1]+1;j <= sum;j++) ans = (ans+f[j])%mod;
    }
    cout << ans;
    return 0;
}
