#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int N=5e3+5;
const int MOD=998244353;
int a[N],n;
ll ans;
ll X[N];
ll s[1100000],top=0;
void build(int n){
    X[1]=1;
    for(int i=2;i<=n;i++){
        X[i]=(i*X[i-1])%MOD;
    }
}
void deal(){
    for(int k=1;k<=n;k++){
        for(int i=0;i<=top;i++){
            s[top+i+1]=s[i]+a[i];
        }
        top*=2;
        if(k>=3){
            sort(s+1,s+top+1);
            int x=s+top-upper_bound(s+1,s+top+1,a[k]*2)+1;
            ans=(ans+x)%MOD;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=20){
        sort(a+1,a+n+1);
        deal();
        cout<<ans;
    }
    else{
        build(n);
        for(int m=3;m<=n;m++){
            ans=(ans+X[n]/X[m])%MOD;
        }
        cout<<ans;
    }
    return 0;
}
