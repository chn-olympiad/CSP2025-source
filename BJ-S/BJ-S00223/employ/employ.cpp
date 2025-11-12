#include <bits/stdc++.h>
using namespace std;
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
#define ll long long
#define rep(i,n) for(int i = 1;i <= n;++i)
#define rpt(i,a,n) for(int i = a;i <= n;++i)
#define pre(i,n) for(int i = n;i;--i)
#define repg(i,u) for(int i = head[u];i;i = e[i].nxt)
#define debug cout<<"Help"<<endl
#define swp(x,y) (x ^= y ^= x ^= y)
bool St;
constexpr int N = 505,mod = 998244353;
int pos[N],c[N],n,m,cnt;
char ch;
bool s[N],flag = true;
ll f[N][N],ans;
inline bool check(){
    int cnt = 0;
    rep(i,n) if(cnt >= c[pos[i]] || !s[i]) ++cnt;
    return n - cnt >= m;
}
inline bool cmp(int x,int y){
    return c[x] < c[y];
}
bool En;
int main(){
//    fin("employ3.in");
    fin("employ.in"),fout("employ.out");
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    rep(i,n) cin>>ch,s[i] = ch ^ 48,flag &= s[i];
    rep(i,n) cin>>c[i];
    if(n <= 10){
        rep(i,n) pos[i] = i;
        do {
            ans += check();
        }while(next_permutation(pos + 1,pos + n + 1));
        cout<<ans;
    }
    else if(n == m){//15
        sort(c + 1,c + n + 1);
        if(!c[1] | !flag) cout<<0;
        else {
            ans = 1;
            rep(i,n) ans = ans * (ll)i % mod;
            cout<<ans;
        }
    }
    else if(flag){
        rep(i,n) pos[i] = i;
        sort(pos + 1,pos + n + 1,cmp);
        f[0][0] = 1;
        rep(i,n) rpt(k,0,i){
            if(k >= c[pos[i]]) f[i][k] = f[i-1][k];
            else if(k) f[i][k] = f[i-1][k-1] * i % mod;
        }
        rpt(i,m,n) ans = (ans + f[n][i]) % mod;
        cout<<ans;
    }
    cerr<<'\n'<<clock() * 1.0 / CLOCKS_PER_SEC;
    cerr<<'\n'<<(&En - &St) / 1024.0 / 1024;
    return 0;
}
//Ren5Jie4Di4Ling5%