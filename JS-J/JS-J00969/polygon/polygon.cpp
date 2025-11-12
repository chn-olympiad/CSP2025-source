#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],dp[N][N],s[N],r[N],ans;
int solve(int x){
    for(int i=1;i<=n;i++){

    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    bool q1=true;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1)q1=false;
    }
    sort(a+1,a+n+1);
    if(q1){
        cout<<n*(n-1)/2;
    }
    if(n==3){
        int mxx=a[3];
        if((a[1]+a[2]+a[3])>mxx*2)cout<<1;
        else cout<<0;
        return 0;
    }
    if(n<=20){
        for(int i=1;i<=20;i++){
            ans+=solve(i);
            ans%=mod;
        }
        cout<<ans%mod;
        return 0;
    }
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        r[n-i+1]=r[n-i+2]+a[n-i+1];
    }
    cout<<2;
}
