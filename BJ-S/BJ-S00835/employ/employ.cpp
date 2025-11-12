#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=1;i<=(n);++i)
#define FILE(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define reb(i,n) for(int i=0;i<(n);++i)
#define ppct __builtin_popcount
#define pb push_back
#define pii pair<int,int>
#define X first
#define Y second
#define mkp make_pair
#define hh(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a,b) memset(a,b,sizeof a)
#define cpy(a,b) memcpy(a,b,sizeof a)
#define lop(i,n) for(int i=n;i;--i)
using namespace std;
const int N=505,mod=998244353,INF=1e18;
double Time(){
    return 1.*clock()/CLOCKS_PER_SEC;
}
bool __st;
void Add(int&a,int b){
    (a+=b)%=mod;
}
void cmin(int&a,int b){
    if(a>b)a=b;
}
int n,m,c[N];
// now at i,x ppl out , y ppl in,z ppl >x ,i-x-y-z ppl <=x
// i placed x+y ppl
string s;
struct sub1{//n<=18
    int dp[1<<18][19];
    int mian(){
        reb(i,n)cin>>c[i];
        dp[0][0]=1;
        rep(i,n){
            reb(j,(1<<n)){
                if(ppct(j)!=(i-1))continue;
                reb(k,n+1){
                    if(!dp[j][k])continue;
                    reb(chs,n){
                    int nw=k;
                        if((1<<chs)&j)continue;
                        if(s[i]=='0'||c[chs]<=k)++nw;
                        if(nw>n)continue;
                        Add(dp[j|(1<<chs)][nw],dp[j][k]);
                    }
                }
            }
        }
        int ans=0;
        hh(i,m,n)Add(ans,dp[(1<<n)-1][n-i]);
        cout<<ans<<"\n";
        return 0;
    }
}ss1;
bool __ed;
int solve(){
    // cout<<(&__st-&__ed)/1024./1024<<"MB\n";
    cin>>n>>m>>s;s=' '+s;
    if(n<=18){
        return ss1.mian();
    }
    rep(i,n)cin>>c[i];
    if(m==1){
        int fac=1;
        rep(i,n)(fac*=i)%=mod;
        sort(c+1,c+1+n);
        int ans=1;
        lop(i,n){
            int s0=0;
            rep(j,c[i])if(s[j]=='0')++s0;
            int pos=(n-c[i]+s0-(n-i));
            if(pos<=0){ans=0;break;}
            (ans*=pos)%=mod;
        }
        cout<<(fac-ans+mod)%mod<<"\n";
        return 0; 
    }
    if(m==n){
        int nd=1;
        rep(i,n)if(s[i]=='0')nd=0;
        rep(i,n)if(c[i]==0)nd=0;
        if(nd==0)return cout<<"0\n",0;
        int fac=1;
        rep(i,n)(fac*=i)%=mod;
        cout<<fac<<'\n';
        return 0;
    }
    cout<<"0\n";
    return 0;
}
main(){
    FILE("employ");
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    // cout<<Time()<<"\n";
    return 0;
}