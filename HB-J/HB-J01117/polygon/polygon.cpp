#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int N=5000;
int n;
int a[N],sum[N];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    sort(a+1,a+1+n);
    //sum[1]=a[1];
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((sum[j]-sum[i-1])>(a[j]*2)){
                ans++;
                cout<<a[i]<<' '<<a[j]<<'\n';
            }
            else continue;
        }
    }
    cout<<ans;
    return 0;
}
