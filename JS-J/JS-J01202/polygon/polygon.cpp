#include<bits/stdc++.h>
#define IO(name) freopen(name".in","r",stdin),freopen(name".out","w",stdout)
using namespace std;
const long long mod=998244353;
int n,a[5005];
long long t[5005][5005],ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    IO("polygon");
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==3){
        sort(a+1,a+1+n);
        if(a[1]+a[2]>a[3]) cout<<1;
        else cout<<0;
        return 0;
    }
    for(int i=0;i<=5000;i++) t[i][i]=1;
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<i;j++){
            t[i][j]=(t[i-1][j-1]+t[i-1][j])%mod;
        }
    }
    for(int i=1;i<=n-2;i++) (ans+=t[n+1][i])%=mod;
    cout<<ans;
    return 0;
}
