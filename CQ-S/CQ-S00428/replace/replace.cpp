#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define repl(i,x,y) for(register int i=(x);i<(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define fir first
#define sec second
#define pub push_back
#define pob pop_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double flt;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
#define put(x) cout<<(x)<<"\n"
#define file(f) freopen(#f".in","r",stdin);freopen(#f".out","w",stdout);

const int N=2e5+5,L=2e6+5;

bool f1;
int n,m;
string S[N][2],T[2];
vector<int> s[N],t;

int cnt=1;
map<int,int> nxt[L];
int fal[L];
int dp[L];
ll dat[L];
vector<int> g[L];
void insert(vector<int> s){
    int x=1;
    for(auto c:s){
        if(!nxt[x][c])nxt[x][c]=++cnt,dp[cnt]=dp[x]+1;//,cerr<<cnt<<":::"<<c<<"\n";
        x=nxt[x][c];
    }
    ++dat[x];
}
void build(){
    repl(i,0,26*26)if(!nxt[1][i])nxt[1][i]=1;else fal[nxt[1][i]]=1;
    rep(i,2,cnt){
        g[fal[i]].pub(i);
        repl(j,0,26*26)if(!nxt[i][j])nxt[i][j]=nxt[fal[i]][j];else fal[nxt[i][j]]=nxt[fal[i]][j];
    }
}
void dfs(vector<int> t,int l,int r){
    int x=1;
    ll sum=0;
    repl(i,0,t.size()){
        x=nxt[x][t[i]];
        if(i>=r){
            // cerr<<x<<" "<<dp[x]<<"\n";
            if(x>1&&i-dp[x]+1<l)sum+=dat[x];
            int y=fal[x];
            while(y>1&&i-dp[y]+1<l){
                sum+=dat[y];
                y=fal[y];
            }
        }
    }
    put(sum);
}

inline void Main(){
    cin>>n>>m;dp[1]=1;
    rep(i,1,n){
        cin>>S[i][0]>>S[i][1];
        int l=S[i][0].size();
        s[i].resize(l);
        repl(j,0,l)s[i][j]=(S[i][0][j]-'a')*26+S[i][1][j]-'a';
        insert(s[i]);
    }
    build();
    // rep(i,1,cnt){
    //     cerr<<i<<":"<<fal[i]<<"\n";
    // }
    rep(i,1,m){
        cin>>T[0]>>T[1];
        if(T[0].size()!=T[1].size()){
            put(0);
            continue;
        }
        int ln=T[0].size();
        t.resize(ln);
        repl(j,0,ln)t[j]=(T[0][j]-'a')*26+T[1][j]-'a';
        int l,r;
        rep(i,0,1e9)if(T[0][i]!=T[1][i]){l=i;break;}
        per(i,T[0].size()-1,0)if(T[0][i]!=T[1][i]){r=i;break;}
        dfs(t,l,r);
    }
}
bool s2;
int main(){
    file(replace);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout<<fixed<<setprecision(16);
    Main();
    return 0;
}