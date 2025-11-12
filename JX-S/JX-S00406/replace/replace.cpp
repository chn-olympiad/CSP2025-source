#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <vector>
#include <queue>
#include <random>
#include <time.h>
#include <unordered_map>
#define int long long
// #define ll long long
// #define db double
// #define db long double
// #define i128 __int128
#define pi pair<int,int>
#define fi first
#define se second

using namespace std;

const int N=2e3+10,base=697891,mod=1e9+7;

int T,n,m,ss,st;
string s[N][2],t[N][2];
vector<int> sum[N];
unordered_map<int,int> mp[N];
int p[N],inv[N];

inline int fastpow(int a,int b){
    int res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

inline void init(){
    p[0]=inv[0]=1;
    p[1]=base,inv[1]=fastpow(base,mod-2);
    for(int i(2);i<N;++i){
        p[i]=p[i-1]*p[1]%mod;
        inv[i]=inv[i-1]*inv[1]%mod;
    }
    for(int i(1);i<=n;++i){
        int now=0,len=s[i][0].length()-1;
        for(int j(1);j<=len;++j){
            now=(now+(s[i][0][j]*13163+s[i][1][j])*p[j])%mod;
        }
        mp[len][now]++;
    }
    for(int i(1);i<=m;++i){
        sum[i].push_back(0);
        int now=0,len=t[i][0].length()-1;
        for(int j(1);j<=len;++j){
            now=(now+(t[i][0][j]*13163+t[i][1][j])*p[j])%mod;
            sum[i].push_back(now);
        }
    }
}

inline int Hash(int i,int l,int r){
    return (sum[i][r]+mod-sum[i][l-1])*inv[l-1]%mod;
}

inline void sol(){
    cin>>n>>m;
    for(int i(1);i<=n;++i){
        cin>>s[i][0]>>s[i][1];
        ss+=s[i][0].length()+s[i][1].length();
        s[i][0]=' '+s[i][0];
        s[i][1]=' '+s[i][1];
    }
    for(int i(1);i<=m;++i){
        cin>>t[i][0]>>t[i][1];
        st+=t[i][0].length()+t[i][1].length();
        t[i][0]=' '+t[i][0];
        t[i][1]=' '+t[i][1];
    }
    if(ss<=2000&&st<=2000){
        init();
        for(int i(1);i<=m;++i){
            int ans=0;
            int len=t[i][0].length()-1;
            int st=1,ed=len;
            for(int j(1);j<=len;++j){
                if(t[i][0][j]!=t[i][1][j]){
                    st=j;
                    break;
                }
            }
            for(int j(len);j>=1;--j){
                if(t[i][0][j]!=t[i][1][j]){
                    ed=j;
                    break;
                }
            }
            for(int l(1);l<=st;++l){
                for(int r(ed);r<=len;++r){
                    int goal=Hash(i,l,r),glen=r-l+1;
                    if(mp[glen].count(goal)){
                        ans+=mp[glen][goal];
                    }
                }
            }
            cout<<ans<<'\n';
        }
    }
    return;
}

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>T;
    T=1;
    while(T--){
        sol();
    }
    return 0;
}