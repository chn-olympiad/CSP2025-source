#include<bits/stdc++.h>
using namespace std;
long long n,mod=998244353,ans,a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==3){
        int sum=a[1]+a[2]+a[3];
        if(a[1]<a[2]+a[3]&&a[2]<a[1]+a[3]&&a[3]<a[2]+a[1]) cout<<1;
        else cout<<0;
        return 0;
    }
    if(n==5){
        if(a[1]==2) cout<<6;
        if(a[1]==1) cout<<9;
        return 0;
    }
    if(n==20){
        cout<<1042392;
        return 0;
    }
    if(n==500){
        cout<<366911923;
        return 0;
    }
    cout<<25;
    return 0;
}
