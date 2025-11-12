#include<bits/stdc++.h>
using namespace std;
long long a[5005],f[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=f[i-1]+a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+a[i];
    }
    if(n<=2){
        cout<<0;
        return 0;
    }
    long long ans=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            long long sum=f[j]-f[i-1];
            for(int k=n;k>=j+1;k--){
                if(sum>a[k]){
                    ans+=k-j;
                    ans%=998244353;
                    break;
                }
            }
            long long s=0;
            for(int k=i-2;k>=1;k--){
                s+=a[k];
                if(sum+s>a[j]*2){
                    ans+=k;
                    ans%=998244353;
                    break;
                }
            }
        }
    }
    cout<<ans;

    return 0;
}
