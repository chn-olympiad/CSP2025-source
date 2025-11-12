#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define int long long
const int N=505,mod=998244353;
int n,m,c[N],ans,sta[N];
string s;
bool vis[N],fl=1,vist[N];
void dfs(int x){
    if(x==n+1) {
        int cnt=0,s=0;
        rep(i,1,n) {
            if(!vis[i]) ++cnt;
            else {
                if(cnt>=c[sta[i]]) ++cnt;
                else ++s;
            }
        }
        if(s>=m) ++ans;
        ans%=mod;
        return ;
    }
    rep(i,1,n) {
        if(!vist[i]) {
            sta[x]=i;
            vist[i]=1;
            dfs(x+1);
            vist[i]=0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cin>>s;
    rep(i,1,n) cin>>c[i];
    rep(i,1,n) {
        if(s[i-1]=='0') vis[i]=0,fl=0;
        else vis[i]=1;
    }
//    if(fl) {
//        ans=1;
//        rep(i,2,n) ans=ans*i%mod;
//        cout<<ans;
//        return 0;
//    }
    dfs(1);
    cout<<ans;
    return 0;
}
