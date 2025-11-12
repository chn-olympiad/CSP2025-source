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
#define int long long
// #define ll long long
// #define db double
// #define db long double
// #define i128 __int128
#define pi pair<int,int>
#define fi first
#define se second

using namespace std;

const int N=20,M=1<<19,mod=998244353;

int T,n,m,a[N],cnt[M],f[2][M][N],id,ans;
vector<int> st[N];
string s;

inline void add(int &x,int y){
    x=x+y<mod?x+y:x+y-mod;
}

inline int lowbit(int x){
    return x&-x;
}

inline int count(int x){
    int res=0;
    while(x){
        res++;
        x-=lowbit(x);
    }
    return res;
}

inline void sol(){
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    for(int i(0);i<n;++i){
        cin>>a[i];
    }
    if(n<20){
        f[0][0][0]=1;
        for(int x(0);x<(1<<n);++x){
            cnt[x]=count(x);
            st[cnt[x]].push_back(x);
        }
        id=0;
        for(int i(0);i<n;++i){
            id^=1;
            memset(f[id],0,sizeof(f[id]));
            int tp=s[i+1]-'0';
            for(auto x:st[i]){
                for(int j(0);j<n;++j){
                    if((x>>j)&1){
                        continue;
                    }
                    int y=x^(1<<j);
                    for(int k(0);k<=n;++k){
                        if(!tp||k>=a[j]){
                            add(f[id][y][k+1],f[id^1][x][k]);
                        }
                        else{
                            add(f[id][y][k],f[id^1][x][k]);
                        }
                    }
                }
            }
        }
        for(int i(0);i<=n-m;++i){
            add(ans,f[id][(1<<n)-1][i]);
        }     
        cout<<ans<<'\n';
    }
    return;
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
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