#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long s[5005],dp[5005][5005];
void g12(int n){
    if(n<3)cout<<0;
    else if(a[3]>=a[2]+a[1])cout<<0;
    else cout<<1;
}
void g36(int n){
    long long sum=0;
    for(int i=3;i<=n;i++){
        long long x=1,y=1;
        for(int j=n;j>=n-i+1;j--){
            x*=j;
        }
        for(int j=1;j<=i;j++){
            y*=j;
        }
        sum+=x/y;
        sum%=998244353;
    }
    cout<<sum;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    bool f=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)f=0;
        s[i]=s[i-1]+a[i];
    }
    sort(a+1,a+1+n);
    if(n<=3)g12(n);
    else if(f)g36(n);
    return 0;
}
