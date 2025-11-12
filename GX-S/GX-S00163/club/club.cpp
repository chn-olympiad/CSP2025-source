#include<bits/stdc++.h>
using namespace std; static int T;
#define reg register
#define _ 7
#define __ 100077
#define ___ 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))
#define sz(a) (int)(a.size())
#define pb push_back
#define all(a) a.begin(),a.end()
#define pct __builtin_popcountll
#define ctz __builtin_ctzll
#define endl '\n'
#define debug cerr<<"LINE:     "<<__LINE__<<endl;
#define cln cerr<<"LINE:     "<<__LINE__<<"     "
#define rep(i,j,k) for(int i=(j);i<=(k);++i)
#define per(i,j,k) for(int i=(j);i>=(k);--i)

using ll=long long; using ull=unsigned long long; using vt=vector<int>;
using vl=vector<ll>; using pii=pair<int,int>; using pll=pair<ll,ll>; using db=double;
constexpr int M=998244353,M1=1e9+7,M2=1e9+9,N=(1<<21)+7,inf=0x3f3f3f3f;
int n,m,dp[__][_],e[__][_]; 
struct dat{
    int a,b,c;
}q[__];
int g[__][_][_];
inline bool cmp(dat a,dat b){
    return (a.a==b.a?(a.b==b.b?a.c>b.c:a.b>b.b):a.a>b.a);
}
inline void solveC(){
    int i,j,k,l,r,x,y,z;
    for(i=0;i<=n+1;++i){
        dp[i][1]=dp[i][2]=dp[i][3]=-1;
        g[i][1][1]=0,g[i][1][2]=0,g[i][1][3]=0;
        g[i][2][1]=0,g[i][2][2]=0,g[i][2][3]=0;
        g[i][3][1]=0,g[i][3][2]=0,g[i][3][3]=0;
        //q[i].a=q[i].b=q[i].c=0;
    }
    // for(i=1;i<=n;++i) cin>>q[i].a>>q[i].b>>q[i].c;
    stable_sort(q+1,q+n+1,cmp);
    for(i=1;i<=n;++i) e[i][1]=q[i].a,e[i][2]=q[i].b,e[i][3]=q[i].c;
    for(i=1;i<=n;++i) dp[i][1]=dp[i][2]=dp[i][3]=-inf;
    dp[1][1]=e[1][1];
    dp[1][2]=e[1][2];
    dp[1][3]=e[1][3];
    g[1][1][1]=1,g[1][1][2]=0,g[1][1][3]=0;
    g[1][2][1]=0,g[1][2][2]=1,g[1][2][3]=0;
    g[1][3][1]=0,g[1][3][2]=0,g[1][3][3]=1;
    for(i=1;i<n;++i){
        for(j=1;j<=3;++j){
            if(g[i][1][j]<n/2){
                if(dp[i+1][j]<dp[i][1]+e[i+1][j]){
                    dp[i+1][j]=dp[i][1]+e[i+1][j];
                    for(k=1;k<=3;++k){
                        if(k==j) g[i+1][j][k]=g[i][1][k]+1;
                        else g[i+1][j][k]=g[i][1][k];
                    }
                }
            }
            if(g[i][2][j]<n/2){
                if(dp[i+1][j]<dp[i][2]+e[i+1][j]){
                    dp[i+1][j]=dp[i][2]+e[i+1][j];
                    for(k=1;k<=3;++k){
                        if(k==j) g[i+1][j][k]=g[i][2][k]+1;
                        else g[i+1][j][k]=g[i][2][k];
                    }
                }
            }
            if(g[i][3][j]<n/2){
                if(dp[i+1][j]<dp[i][3]+e[i+1][j]){
                    dp[i+1][j]=dp[i][3]+e[i+1][j];
                    for(k=1;k<=3;++k){
                        if(k==j) g[i+1][j][k]=g[i][3][k]+1;
                        else g[i+1][j][k]=g[i][3][k];
                    }
                }
            }
        }
    }cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
}
inline void solveA(){ int ans=0;
    stable_sort(q+1,q+n+1,cmp);
    for(int i=1;i<=n/2;++i) ans+=q[i].a;
    cout<<ans<<endl;
}
int a,b,c,answ;
void dfs(int x,int y){
    if(x==n+1){
        answ=max(answ,y);
        return ;
    }
    if(a<n/2){
        ++a,dfs(x+1,y+q[x].a); --a;
    }
    if(b<n/2){
        ++b,dfs(x+1,y+q[x].b); --b;
    }
    if(c<n/2){
        ++c,dfs(x+1,y+q[x].c); --c;
    } return ;
}
void solve(){
    a=0,b=0,c=0; answ=-1;
    dfs(1,0);
    cout<<answ<<endl;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,k,l,r,x,y,z;
    for(cin>>T;T;--T){
        cin>>n;
        for(i=0;i<=n+7;++i) q[i].a=q[i].b=q[i].c=0;
        for(i=1;i<=n;++i) cin>>q[i].a>>q[i].b>>q[i].c;
        if(n<=10){
            solve(); continue;
        }
        int tot=0,ttot=0;
        for(i=1;i<=n;++i){
            if(q[i].b==0) ++tot;
            else if(q[i].c==0) ++ttot;
        }
        if(tot==ttot&&ttot==n){
            solveA(); continue;
        }else{
            solveC();
        }
    }
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/