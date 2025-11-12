#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int mod=998244353;

int n;
int a[N];
int vis[N];
long long f[N];
long long ans=0;

void dfs(int step){
    if(step==n+1){
        int maxn=0;
        long long sum=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==1){
                sum+=a[i];
                maxn=max(maxn,a[i]);
            }
        }
        if(sum>maxn*2) ans++;
    } else {
        vis[step]=1;
        dfs(step+1);
        vis[step]=0;
        dfs(step+1);
    }
}

long long fast_pow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

long long inv(long long x){
    return fast_pow(x,mod-2);
}

long long C(long long n,long long m){
    return (f[n]*inv(f[m]*f[n-m]%mod)%mod)%mod;
}

void init(){
    f[0]=1;
    for(int i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
    }
}

bool check1(){
    int p=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=1){
            p=0;
            break;
        }
    }
    if(p==1){
        init();
        long long res=0;
        for(int i=3;i<=n;i++){
            res=(res+C(n,i))%mod;
        }
        cout<<res;
        return 1;
    } else {
        return 0;
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=3){
        if(n!=3){
            cout<<0;
            return 0;
        }
        long long maxn=max(a[1],a[2]);
        maxn=max(a[2],a[3]);
        long long add=a[1]+a[2]+a[3];
        if(add>maxn*2) cout<<1;
        else cout<<0;
        return 0;
    }
    if(check1()) return 0;
    dfs(1);
    cout<<ans;
    return 0;
}