#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],f[5005],mod=998244353,ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]>a[3]){
            cout<<"1";
        }
        else cout<<"0";
        return 0;
    }
    if(a[1]==a[n]){
        ans=1;
        for(int i=1;i<=n;i++){
            ans=ans*2%mod;
        }
        cout<<ans%mod-n;
        return 0;
    }
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+a[i];
        for(int j=1;j<=n;j++){
            if(j<=i){
                if(a[j+1]>=f[i]-a[j]){
                    ans=(ans+j-1)%mod;
                }
            }
            else if(a[j+1]>=f[i]){
                ans=(ans+j)%mod;
            }
        }
    }
    cout<<ans;
    return 0;
}
