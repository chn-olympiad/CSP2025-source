#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int N=505;
const int mod=998244353;
int n,m,c[N],b[N];
ll ans=0,dp[20][20][1<<18];
vector<int> ren[20];
int flag1=1;
string s;
inline int get1(int w){
    int res=0;
    while(w){if(w&1)res++;w>>=1;}
    return res;
}
inline bool check(){
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(s[i]=='0'||cnt>=c[b[i]])++cnt;
    }
    if(n-cnt>=m)return true;
    return false;
}
inline void solve(){
    for(int i=1;i<=n;++i)if(s[i]!='1')return;
    for(int i=1;i<=n;++i)if(!c[i])return;
    ans=1;
    for(int i=1;i<=n;++i)ans=ans*i%mod;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;s=" "+s;
    for(int i=1;i<=n;++i)cin>>c[i];
    for(int i=1;i<=n;++i)if(s[i]=='0')flag1=0;
    if(n<=10){
        for(int i=1;i<=n;++i)b[i]=i;
        if(check())++ans;
        while(next_permutation(b+1,b+1+n))if(check())++ans;
    }
    else if(n<=18){
        for(int i=0;i<(1<<n);++i)ren[get1(i)].push_back(i);
        dp[0][0][0]=1;
        for(int i=1;i<=n;++i){
            for(int j=0;j<i;++j){
                for(int k:ren[i-1]){
                    for(int p=1;p<=n;++p){
                        if((k>>p-1)&1)continue;
                        if(j>=c[p]||s[i]=='0')dp[i][j+1][k|(1<<p-1)]=(dp[i][j+1][k|(1<<p-1)]+dp[i-1][j][k])%mod;
                        else dp[i][j][k|(1<<p-1)]=(dp[i][j][k|(1<<p-1)]+dp[i-1][j][k])%mod;
                    }
                }
            }
        }
        for(int j=0;j+m<=n;++j)ans=(ans+dp[n][j][(1<<n)-1])%mod;
    }
    else if(m==n){
        solve();
    }
    cout<<ans;
    return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
