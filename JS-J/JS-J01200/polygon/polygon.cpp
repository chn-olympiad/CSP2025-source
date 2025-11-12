#include<bits/stdc++.h>
using namespace std;
int n,a[500009],sum=0,h[500009];
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n==3) {
        if(a[1]+a[2]>a[3]) cout<<1;
        else cout<<0;
        return 0;
    }
    long long sum=1;
    for(int i=1;i<=n-4;i++) {
        sum*=i;
        sum%=998244353;
    }
    cout<<sum%998244353;;
    return 0;
}
