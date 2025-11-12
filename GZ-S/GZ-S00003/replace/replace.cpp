// GZ-S00003 丁思源   贵阳市华师一学校

#include <bits/stdc++.h>

using namespace std;

// #define ll long long
#define ll int

#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
#define vi vector<ll>
#define ull unsigned ll
#define pb push_back
#define SZ(x)  ((int)x.size())
#define BG(x) (x.begin())
#define ED(x) (x.end())
#define pii pair<ll,ll>
#define x first
#define y second
#define mkp make_pair
#define gmin(x,y) (x=min(x,y))
#define gmax(x,y) (x=max(x,y))
#define MD(x) ((x)%=mod)
#define ppct __builtin_popcountll

// bool p=0;

namespace Mine {
    #define gc getchar
    ll read() {
        ll x=0,t=1;
        char ch=gc();
        while(ch<'0' || ch>'9') t=(ch=='-'?-1:t),ch=gc();
        while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=gc();
        return t*x;
    }
    #undef gc
    const ll N=2e5+100,P=13331,M=1e7+100;
    ll n,q;
    ull p[M];
    string s1[N],s2[N];
    string t1[N],t2[N];
    pii poss[N],post[N];
    struct H {
        ull ha[M];
        void build(string ch) {
            ll n=SZ(ch)-1;
            For(i,1,n) {
                ha[i]=ha[i-1]*P+ch[i]-'a'+1;
            }
        }
        ull get(ll ql,ll qr) {
            return ha[qr]-ha[ql-1]*p[qr-ql+1];
        }
    } h1,h2;
    ll son[M][26],idx=2,root=2,pos[M],dfn[M],R[M],tot=1,ccc=0,ans[N];
    vector<pii> vec[N*2];
    void init() {
        For(i,0,idx+100) {
            memset(son[i],0,sizeof(son[i]));
            vec[pos[i]].clear();
            dfn[i]=R[i]=pos[i]=0;
        }
        idx=2;
        ccc=0,tot=0;
    }
    void dfs(ll u) {
        if(!u) return ;
        dfn[u]=++ccc;
        For(j,0,25) if(son[u][j]) dfs(son[u][j]);
        R[u]=ccc;
    }
    struct trie {
        ll root=1;
        ll ins(string ch) {
            if(!root) root=++idx;
            ll len=SZ(ch)-1,u=root;
            For(i,0,len) {
                ll & to=son[u][ch[i]-'a'];
                if(!to) to=++idx;
                u=to;
            }
            return u;
        }
    } T;
    map<pair<ull,ull>,vector<pii> > mp;
    struct bit {
        ll tr[M];
        void mdf(ll pos,ll val) {
            for(pos++;pos<idx+5;pos+=pos&-pos) tr[pos]+=val;
        }
        ll ask(ll pos) {
            ll ret=0;
            // ret=tr[pos];
            for(pos++;pos;pos&=pos-1) ret+=tr[pos];
            return ret;
        }
        void mdf(ll ql,ll qr,ll val) {
            // For(i,q,qr) tr[i]+=val;
            mdf(ql,val),mdf(qr+1,-val);
        }
    } BIT;
    multiset<int> S;
    void solve(ll u) {
        if(!u) return ;
        if(pos[u])
        for(auto j:vec[pos[u]]) {
            if(j.y==-1) {
                BIT.mdf(dfn[j.x],R[j.x],1);
                S.insert(j.x);
            } else {
                // if(j.y==236) {
                //     // cout<<BIT.ask(dfn[j.x])<<" "<<SZ(S)<<endl;
                //     for(auto u:S) {
                //         cout<<dfn[u]<<" "<<dfn[j.x]<<" "<<R[u]<<endl;
                //         if(dfn[u]<=dfn[j.x] && dfn[j.x]<=R[u]) {
                //             cout<<u<<"A ";
                //             string s;
                //             while(u!=1) {
                //                 s=(char)(in[u]+'a')+s;
                //                 u=fa[u];
                //             }
                //             cout<<s<<endl;
                //             s="";
                //             u=j.x;
                //             while(u!=1) {
                //                 s=(char)(in[u]+'a')+s;
                //                 u=fa[u];
                //             }
                //             cout<<s<<endl;
                //         }
                //     }
                // }
                ans[j.y]=BIT.ask(dfn[j.x]);
            }
        }
        For(j,0,25) if(son[u][j]) solve(son[u][j]);
        if(pos[u])
        for(auto j:vec[pos[u]]) {
            if(j.y==-1) {
                S.erase(S.find(j.x));
                BIT.mdf(dfn[j.x],R[j.x],-1);
            }
        }
    }
    void main() {
        p[0]=1; For(i,1,M-1) p[i]=p[i-1]*P;
        n=read(),q=read();
        For(i,1,n) {
            cin>>s1[i]>>s2[i];
            if(s1[i]==s2[i]) continue;
            s1[i]=" "+s1[i],s2[i]=" "+s2[i];
            h1.build(s1[i]),h2.build(s2[i]);
            ll ql=1,len=(int)s1[i].size()-1,qr=len;
            while(qr>=1 && s1[i][qr]==s2[i][qr]) qr--;
            if(qr==0) continue;
            while(ql<=len && s1[i][ql]==s2[i][ql]) ql++;
            ull tmp=h1.get(ql,qr);
            poss[i]=mkp(ql,qr);
            mp[mkp(h1.get(ql,qr),h2.get(ql,qr))].pb(mkp(i,-1));
        }

        For(i,1,q) {
            cin>>t1[i]>>t2[i];
            t1[i]=" "+t1[i],t2[i]=" "+t2[i];
            h1.build(t1[i]),h2.build(t2[i]);
            ll ql=1,len=(int)t1[i].size()-1,qr=len;
            while(qr>=1 && t1[i][qr]==t2[i][qr]) qr--;
            if(qr==0) continue;
            while(ql<=len && t1[i][ql]==t2[i][ql]) ql++;
            ull tmp=h1.get(ql,qr);
            post[i]=mkp(ql,qr);
            // cout<<ql<<" "<<qr<<endl;
            // cout<<
            mp[mkp(h1.get(ql,qr),h2.get(ql,qr))].pb(mkp(i,1));
        }

        for(auto t:mp) {
            auto v=t.y;
            init();
            string ch1,ch2;
            for(auto j:v) {
                ll i=j.x;
                if(j.y==-1) {
                    ll p=T.ins(s1[i].substr(poss[i].y+1));
                    ll u=2;
                    Rof(j,poss[i].x-1,1) {
                        ll & to=son[u][s1[i][j]-'a'];
                        if(!to) to=++idx;
                        u=to;
                    }
                    if(!pos[u]) pos[u]=++tot;
                    vec[pos[u]].pb(mkp(p,-1));
                } else {
                    ll p=T.ins(t1[i].substr(post[i].y+1));
                    // if(i==236) {
                    //     cout<<t1[i].substr(post[i].y)<<endl;
                    // }
                    ll u=2;
                    Rof(j,post[i].x-1,1) {
                        ll & to=son[u][t1[i][j]-'a'];
                        if(!to) break;
                        u=to;
                    }
                    if(!pos[u]) pos[u]=++tot;
                    vec[pos[u]].pb(mkp(p,i));
                }
            }
            dfs(1);
            solve(2);
            // puts("----------");
        }
        For(i,1,q) {
            // if(i==236) {
            //     cout<<t1[i]<<" "<<t2[i]<<endl;
            //     cout<<t1[i].substr(post[i].y+1)<<endl;
            // }
            cout<<ans[i]<<"\n";
        }

    }
}

// bool p2=0;

signed main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ll _=1;
    while(_--) Mine::main();
    // cerr<<&p2-&p<<endl;
    return 0;
}