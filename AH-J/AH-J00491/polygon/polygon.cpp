#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],f[5005],g[5005],ans;
const int mod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long w=2;
    f[0]=1;
    for(int i=1;i<n;i++){
        for(int j=a[n];j>=a[i];j--){
            f[j]=(f[j]+f[j-a[i]])%mod;
        }
        int cnt=0;
        for(int j=0;j<=a[i+1];j++)cnt=(cnt+f[j])%mod;
        ans=(ans+w-cnt+mod)%mod;
        w=w*2%mod;
    }
    cout<<ans;
    return 0;
}
