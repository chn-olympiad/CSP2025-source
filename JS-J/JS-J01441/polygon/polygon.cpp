#include<bits/stdc++.h>
using namespace std;
int n;
long long t;
long long a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t=max(a[i],t);
    }
    if(t==1){
        t=0;
        for(int i=3;i<=n;i++){
            long long ans=1;
            for(int j=1;j<=i;j++){
                ans=ans*(n-j+1)/j;
            }
            t+=ans;
        }
        cout<<t%998244353;
        return 0;
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]>a[3]) cout<<1;
        else cout<<0;   
        return 0;
    }
    return 0;
}