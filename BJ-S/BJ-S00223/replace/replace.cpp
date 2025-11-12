#include <bits/stdc++.h>
using namespace std;
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
#define uint unsigned long long
#define rep(i,n) for(int i = 1;i <= n;++i)
#define rpt(i,a,n) for(int i = a;i <= n;++i)
#define pre(i,n) for(int i = n;i;--i)
#define repg(i,u) for(int i = head[u];i;i = e[i].nxt)
#define debug cout<<"Help"<<endl
#define swp(x,y) (x ^= y ^= x ^= y)
bool St;
constexpr int N = 2005,base = 233;
int n,q,l;
uint hsh[N][2][N],h[2][N],pw[N],ans;
inline int gethsh(uint * hsh,int l,int r){
    if(l > r) return 0;
    return hsh[r] - hsh[l-1] * pw[r-l+1];
}
string s[N][2],a,b;
bool En;
int main(){
//    fin("replace2.in");
    fin("replace.in"),fout("replace.out");
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    pw[0] = 1;
    rep(i,2000) pw[i] = pw[i-1] * base;
    rep(i,n){
        cin>>s[i][0]>>s[i][1],l = s[i][0].length();
        s[i][0] = " " + s[i][0],s[i][1] = " " + s[i][1];
        rep(j,l) hsh[i][0][j] = hsh[i][0][j-1] * base + s[i][0][j],hsh[i][1][j] = hsh[i][1][j-1] * base + s[i][1][j];
    }
    while(q--){
        cin>>a>>b;
        if(a.length() ^ b.length()){
            cout<<"0\n";
            continue;
        }
        l = a.length(),a = " " + a,b = " " + b,ans = 0;
        rep(i,l) h[0][i] = h[0][i-1] * base + a[i],h[1][i] = h[1][i-1] * base + b[i];
        rep(i,n){
            int len = s[i][0].length() - 1;
            rep(j,l - len + 1){
                if(gethsh(h[0],1,j - 1) ^ gethsh(h[1],1,j - 1) || gethsh(h[0],j + len,l) ^ gethsh(h[1],j + len,l)) continue;
                if(gethsh(hsh[i][0],1,len) ^ gethsh(h[0],j,j + len - 1)) continue;
                if(gethsh(hsh[i][1],1,len) == gethsh(h[1],j,j + len - 1)) ++ans;
            }
        }
        cout<<ans<<'\n';
    }
    cerr<<'\n'<<clock() * 1.0 / CLOCKS_PER_SEC;
    cerr<<'\n'<<(&En - &St) / 1024.0 / 1024;
    return 0;
}
//Ren5Jie4Di4Ling5%
