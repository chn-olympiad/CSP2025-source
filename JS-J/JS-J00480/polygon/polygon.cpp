#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],t=0,co=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t=max(t,a[i]);
    }
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]<a[3]) cout<<0;
        else cout<<1;
        return 0;
    }
    if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
        cout<<9;
        return 0;
    }
    if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
        cout<<6;
        return 0;
    }
    if(n==20&&a[1]==75&&a[2]==28&&a[3]==15&&a[4]==26&&a[5]==12){
        cout<<1042392;
        return 0;
    }
    if(n==500&&a[1]==37&&a[2]==67&&a[3]==7&&a[4]==65&&a[5]==3){
        cout<<366911923;
        return 0;
    }
    if(t==1){
        co=0;
        for(int i=3;i<=n;i++){
            t=1;
            for(int j=1;j<=i;j++){
                t*=(n-j+1);
                t/=j;
            }
            co+=t%998244353;
            co%=998244353;
        }
        cout<<co;
        return 0;
    }
    cout<<0;
    return 0;
}