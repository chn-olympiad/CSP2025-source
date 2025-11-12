#include <bits/stdc++.h>
using namespace std;
long long n,a[25]={},ans=0,b[25]={};
void f(long long maxx,long long sum,long long k,long long p) {
    if (sum>2*maxx && k>=3) ans++,ans=ans%998244353;
    for (long long i=p;i<=n;i++) {
        if (!b[i]) {
            b[i]=1;
            f(max(maxx,a[i]),sum+a[i],k+1,i+1);
            b[i]=0;
        }
    }
}
int main () {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (long long i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    f(0,0,0,1);
    cout << ans;
    return 0;
}
