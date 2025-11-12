#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(r);i>=(l);--i)
#define pr pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define bg(x) (x).begin()
#define ed(x) (x).end()
#define sz(x) (int)(x).size()

#define N 505
#define int long long

const int mod=998244353;

int n,m,a[N],c[N];

inline void add(int &x,int y){
    // x=(x+y+mod)%mod;
    x+=y;
    if(x>=mod){
        x-=y;
    }
}

namespace bf{
    int tot;
    #define S (262144+5)

    int f[S][19],g[S][19];

    signed main(){
        tot=(1<<n)-1;

        f[0][0]=1;

        rep(i,1,n){
            memcpy(g,f,sizeof f);
            memset(f,0,sizeof f);

            rep(s,0,tot){
                rep(k,1,n){
                    if(s>>(k-1)&1){
                        continue;
                    }
                    int t=s^(1<<(k-1));

                    rep(j,0,i){
                        int re=g[s][j];

                        if(!re){
                            continue;
                        }

                        if(j<c[k]){
                            add(f[t][j+!a[i]],re);
                        }
                        else{
                            add(f[t][j+1],re);
                        }
                    }
                }
            }
        }

        int ans=0;

        rep(i,0,n-m){
            add(ans,f[tot][i]);
        }

        cout<<ans<<'\n';
        
        return 0;
    }
}

namespace s1{
    ;

    signed main(){
        ;

        return 0;
    }
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;

    rep(i,1,n){
        char c;
        cin>>c;
        a[i]=c-'0';
    }

    rep(i,1,n){
        cin>>c[i];
    }

    if(n<=18){
        return bf::main();
    }

    if(*min_element(a+1,a+1+n)==1){
        return s1::main();
    }

    /*
    g++ employ.cpp -o employ -O2 -std=c++14 -Wall -Wextra -Wshadow
    */

    return 0;
}