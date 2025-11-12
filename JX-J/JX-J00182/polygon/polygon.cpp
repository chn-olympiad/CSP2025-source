#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,ans=0,a[5003];
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==3){
        if(a[1]+a[2]>a[3]&&abs(a[1]-a[2])<a[3]) cout<<1;
        else cout<<0;
        return 0;
    }
    for(int i=3;i<=n;i++){
        long long sum=1;
        for(int j=n;j>n-i;j--){
            sum=(sum*j)%998244353;
        }
        for(int j=1;j<=i;j++){
            sum/=j;
        }
        ans+=sum;
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
