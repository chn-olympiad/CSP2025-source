#include<bits/stdc++.h>
using namespace std;
int n;
int a[114514];
long long ans;
const int mod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=3){
        if(n<3)cout<<0;
        else{
            if(a[1]*2<a[1]+a[2]+a[3]&&a[2]*2<a[1]+a[2]+a[3]&&a[3]*2<a[1]+a[2]+a[3])cout<<1;
            else cout<<0;
        }
    }else{
        for(int i=3;i<=n;i++){
            long long ans2=1;
            for(int j=i+1;j<=n;j++)ans2=(ans2%mod*j%mod)%mod;
            for(int j=2;j<=n-i;j++)ans2/=j;
            ans=(ans%mod+ans2%mod)%mod;
        }
        cout<<ans;
    }
    return 0;
}
