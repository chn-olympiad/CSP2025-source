#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
using namespace std;
const int p=998244353;
void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    s=" "+s;
    vector<int>c(n+2);
    vector<int>f(n+2);
    rep(i,1,n) cin>>c[i];
    rep(i,1,n) f[i]=i;
    int ans=0;
    do{
        int t=0,cnt=0;
        // cout<<"sb";
        // cout<<'\n';
        rep(x,1,n){
            int i=f[x];
            if(s[x]=='0'||cnt>=c[i]) {
                // if(cnt>=c[i]) cout<<"sb";
                // cout<<cnt << ' '<<c[i]<<' ' << i<<'\n';
                ++cnt;
            }
            else ++t;
            if(t==m){
                ans=(ans+1)%p;
                break;
            }
        }
    }while(next_permutation(f.begin()+1,f.begin()+n+1));
    cout<<ans<<'\n';
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int T=1; 
    // cin>>T;
    for(;T;--T){
        solve();
    }
    return 0;
}
/*
g++ employ.cpp -o employ -std=c++14 -O2 -Wall
*/