#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int mod=998244353;
int n,a[5555];
long long fact[5555],invfact[5555];
long long ans=0;
void dfs(int pos,int sum,int maxx,int cnt,int last){
    if(cnt>=3&&sum>2*maxx&&last!=cnt){
        ans++,ans%=mod;
        last=cnt;
    }
    if(pos>n)
        return;
    dfs(pos+1,sum,maxx,cnt,last);
    dfs(pos+1,sum+a[pos],max(maxx,a[pos]),cnt+1,last);
    return;
}
long long qpow(long long base,long long power=mod-2,int mod=mod){
    long long res=1;
    while(power){
        if(power&1)
            res*=base,res%=mod;
        base*=base,base%=mod;
        power>>=1;
    }
    return res;
}
void init(){
    fact[0]=1;
    for(int i=1;i<=5000;i++)
        fact[i]=fact[i-1]*i%mod;
    invfact[5000]=qpow(fact[5000]);
    for(int i=4999;i>=0;i--)
        invfact[i]=invfact[i+1]*(i+1)%mod;
    return;
}
long long C(int m,int n){
    if(n==0||n>m)
        return 0;
    return fact[m]*invfact[n]%mod*invfact[m-n]%mod;
}
void solve(){
    cin>>n;
    int maxx=-1;
    for(int i=1;i<=n;i++)
        cin>>a[i],maxx=max(a[i],maxx);
    if(maxx!=1){
        dfs(1,0,0,0,0);
        cout<<ans<<endl;
    }else{
        init();
        long long ans=0;
        for(int i=3;i<=n;i++)
            ans+=C(n,i),ans%=mod;
        cout<<ans<<endl;
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}
/*
60pts
*/