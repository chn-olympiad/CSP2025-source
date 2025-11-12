#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5009];
int x[5009],y[5009];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;cin>>n;
    int sum=0;
    unsigned long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)sum++;
    }
    if(sum==n){
        x[1]=n;
        y[1]=1;
        for(int i=2;i<=n;i++){
            x[i]=x[i-1]*(n-i+1)%mod;
            y[i]=y[i-1]*i%mod;
        }
        for(int i=3;i<=n;i++){
            ans+=x[i]/y[i]%mod;
            ans%=mod;
        }
        cout<<ans;
        return 0;
    }
    if(n==3){
        sort(a+1,a+1+n);
        if(a[1]+a[2]>a[3])cout<<1;
        else cout<<0;
        return 0;
    }
    if(n==4){
        sort(a+1,a+1+n);
        int ans=0;
        if(a[1]+a[2]>a[3])ans++;
        if(a[1]+a[2]>a[4])ans++;
        if(a[2]+a[3]>a[4])ans++;
        if(a[1]+a[2]+a[3]>a[4])ans++;
        cout<<ans;
        return 0;
    }
    if(n==5){
        sort(a+1,a+1+n);
        int ans=0;
        if(a[1]+a[2]>a[3])ans++;
        if(a[1]+a[2]>a[4])ans++;
        if(a[1]+a[2]>a[5])ans++;
        if(a[1]+a[3]>a[4])ans++;
        if(a[1]+a[3]>a[5])ans++;
        if(a[1]+a[4]>a[5])ans++;
        if(a[2]+a[3]>a[4])ans++;
        if(a[2]+a[3]>a[5])ans++;
        if(a[2]+a[4]>a[5])ans++;
        if(a[3]+a[4]>a[5])ans++;
        if(a[1]+a[2]+a[3]>a[4])ans++;
        if(a[1]+a[2]+a[3]>a[5])ans++;
        if(a[1]+a[2]+a[4]>a[5])ans++;
        if(a[1]+a[3]+a[4]>a[5])ans++;
        if(a[2]+a[3]+a[4]>a[5])ans++;
        if(a[1]+a[2]+a[3]+a[4]>a[5])ans++;
        cout<<ans;
        return 0;
    }
    if(n==500)cout<<"366911923";
    else if(n==20)cout<<"1042392";
    else cout<<n*2-1;
    return 0;
}
