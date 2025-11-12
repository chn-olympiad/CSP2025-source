#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],ans,mx;
int f[5010][5010];

void dfs(int pos,int sum,int mx,int res){
    if(pos>n){
        if(res>2*mx&&sum>=3) ans++;
        ans%=mod;
        return;
    }
    dfs(pos+1,sum,mx,res);
    dfs(pos+1,sum+1,max(mx,a[pos]),res+a[pos]);
}
int qpow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) (res*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return res;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(n<=20){
        dfs(1,0,0,0);
        cout<<ans<<"\n";
        return 0;
    }
    if(mx<=1){
        int ans=qpow(2,n)-1-n-n*(n-1)/2;
        if(ans<0) ans+=mod;
        cout<<ans<<"\n";
        return 0;
    }
    sort(a+1,a+1+n);
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        f[i][0]=1;
        for(int j=5000;j>0;j--){
            if(j>=a[i]) (f[i][j]+=f[i-1][j-a[i]]+f[i-1][j])%=mod;
            else f[i][j]=f[i-1][j];
        }
        if(i>=3){
            for(int j=2*a[i]+1;j<=5000;j++){
                (ans+=f[i][j])%=mod;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}   