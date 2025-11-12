#include<bits/stdc++.h>
using namespace std;
int a[5005];
const long long mod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=3){
        if(n<=2){
            cout<<0;
        }else{
            if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2)cout<<1;
            else cout<<0;
        }
        return 0;
    }else{
        long long ans=0;
        for(int i=3;i<=n;i++){
            long long cunt=1;
            for(int j=n;j>=n-i+1;j--){
                cunt=(cunt*j)%mod;
            }
            long long p=1;
            for(int j=1;j<=i;j++){
                cunt=(cunt/j)%mod;
            }
            ans=(ans+cunt)%mod;
        }
        cout<<ans;
    }
    return 0;
}
