#include <bits/stdc++.h>
#define lint __int128
#define int long long
#define fi first
#define se second
#define Il inline
#define vec vector
#define pb push_back
#define IT ::iterator
#define p_q priority_queue

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef double db;
const int N=500,mod=998244353;
const db eps=1e-9;

// bool P1;

Il int qpow(int x,int y){
    int t=1;
    for(;y;y>>=1,x=x*x%mod){
        if(y&1){
            t=t*x%mod;
        }
    }
    return t;
}

int n,m,a[N+5],b[N+5],ans=0,jc[N+5],iv[N+5];
bool vis[N+5];
string s;

Il int C(int x,int y){
    return x<0||y<0||x<y?0:jc[x]*iv[y]%mod*iv[x-y]%mod;
}

Il void dfs(int p){
    if(p>n){
        int c=0,cc=0;
        for(int i=1;i<=n;i++){
            if(c>=a[b[i]]||s[i]=='0'){
                c++;
            }else{
                cc++;
            }
        }
        ans=(ans+(cc>=m))%mod;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        b[p]=i,vis[i]=1,dfs(p+1),b[p]=vis[i]=0;
    }
    return;
}

Il void solve1(){
    dfs(1);
    cout<<ans;
    return;
}

Il void solve2(){
    int c=0;
    for(int i=1;i<=n;i++){
        if(a[i]){
            c++;
        }
    }
    cout<<(c>=m?jc[c]*C(n,c)%mod:0ll);
    return;
}

// bool P2;

signed main(){
    // system("diff club5.ans club.out -Z");return 0;
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // cout<<abs((&P1)-(&P2))/1024/1024;return 0;
    jc[0]=1;
    for(int i=1;i<=N;i++){
        jc[i]=jc[i-1]*i%mod;
    }
    iv[N]=qpow(jc[N],mod-2);
    for(int i=N-1;~i;i--){
        iv[i]=iv[i+1]*(i+1)%mod;
    }
    cin>>n>>m>>s,s=" "+s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=10){
        solve1();
    }
    return 0;
}