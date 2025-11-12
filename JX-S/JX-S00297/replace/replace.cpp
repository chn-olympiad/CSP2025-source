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

#define N 2002511
#define int long long

const int mod=919178699;
const int mul=697891;
int n,m,pw[N],a[N],v[N];

struct trie{
    int cnt,t[N][26];
    vector<int>e[N];

    inline void ins(string &s,int i){
        int u=0;

        for(char c:s){
            int x=c-'a';
            if(!t[u][x]){
                t[u][x]=++cnt;
            }

            u=t[u][x];
        }

        e[u].pb(i);
    }
}t;

inline int get(int l,int r,int *ha){
    if(r>l){
        return 0;
    }
    return (ha[r]-ha[l-1]*pw[r-l+1]%mod+mod)%mod;
}

string sa,sb;
int len=0;

inline void sol(){
    cin>>sa>>sb;
    len=sz(sa);

    sa=' '+sa;
    sb=' '+sb;
    int hb=0;

    rep(i,1,len){
        a[i]=(a[i-1]*mul%mod+sa[i])%mod;
        hb=(hb*mul%mod+sb[i])%mod;
    }

    int ans=0;

    rep(i,1,len){
        int u=0;

        rep(j,i,len){
            int x=sa[j]-'a';
            if(!t.t[u][x]){
                break;
            }
            u=t.t[u][x];

            for(int x:t.e[u]){
                int re=a[i-1]*pw[len-i+1]%mod+v[x]*pw[len-j]%mod+get(j+1,len,a);
                re%=mod;

                if(re==hb){
                    ans++;
                }
            }
        }
    }

    cout<<ans<<'\n';
}

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;

    pw[0]=1;
    rep(i,1,1e6){
        pw[i]=pw[i-1]*mul%mod;
    }

    rep(i,1,n){
        string s,ss;
        cin>>s>>ss;

        t.ins(s,i);

        int re=0;
        for(char c:ss){
            re=(re*mul%mod+c)%mod;
        }
        v[i]=re;
    }

    rep(i,1,m){
        sol();
    }

    /*
    g++ replace.cpp -o replace -O2 -std=c++14 -Wall -Wextra -Wshadow
    */

    return 0;
}