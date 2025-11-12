#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],sum[5005],cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","r",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=3;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            if(sum[i+j-1]-sum[j-1]>a[i+j-1]*2) cnt++;
            cout<<i+j-1<<' '<<j-1<<' '<<sum[i+j-1]-sum[j-1]<<' '<<a[i+j-1]*2<<'\n';
        }
    }
    cout<<cnt%998244353;
    return 0;
}
