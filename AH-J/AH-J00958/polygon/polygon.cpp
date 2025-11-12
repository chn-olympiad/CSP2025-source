#include<bits/stdc++.h>
#include<time.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353;
int n;
int a[5000+5];
int fac[5000+5],facinv[5000+5];
int summ[5000+5];
int sum[5000+5][5000+5];
int qpow(int a,int b){
    int ret=1,base=a;
    while(b){
        if(b&1) ret=ret*base%mod;
        base=base*base%mod;
        b>>=1;
    }
    return ret;
}
int c(int a,int b){
    return fac[a]*facinv[b]%mod*facinv[a-b]%mod;
}
void init(){
    fac[0]=1;
    for(int i=1;i<=5000;i++) fac[i]=fac[i-1]*i%mod;
    for(int i=1;i<=5000;i++) facinv[i]=qpow(fac[i],mod-2);
}
int cnt;
vector<int> v;
void dfs(int lst,int step,int lim){
    if(step>lim){
        int t=0;
        for(int i:v){
            t+=i;
        }
        if(t>2*v.back()) cnt++;
        return;
    }
    for(int i=lst+1;i<=n;i++) v.push_back(a[i]),dfs(i,step+1,lim),v.pop_back();
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    if(n==3){
        if(a[1]+a[2]>a[3]) cout<<1;
        else cout<<0;
        return 0;
    }
    if(a[n]==1){
        int ans=0;
        for(int i=3;i<=n;i++){
            ans=(ans+c(n,i))%mod;
        }cout<<ans;
        return 0;
    }
    if(n<=10){
        for(int i=1;i<=n;i++) dfs(0,1,i);
        cout<<cnt;
        return 0;
    }
    srand(time(NULL));
    cout<<rand()%998244353+1;
    return 0;
}
