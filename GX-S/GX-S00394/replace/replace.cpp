#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define For(x,l,r) for(ll x=l;x<=r;++x)
#define Rof(x,l,r) for(ll x=r;x>=l;--x)
#define pb push_back

const int mod = 998244353, N = 2e5+5, BS = 37;

int n,q;
string s[3][N];
string t[3];

void solve(){
    cin>>n>>q;
    For(i,1,n) For(j,1,2) cin>>s[j][i];
    while(q--){
        cin>>t[1]>>t[2];
        int ans=0;
        int lent=t[1].size();
        For(i,1,n){
            int lens=s[1][i].size();
            For(st,0,lent-1){
                if(st+lens-1>lent) break;
                int fl=1;
                For(j,0,lens-1){
                    if(t[1][st+j]!=s[1][i][j]){
                        fl=0;
                        break;
                    }
                }
                if(fl==0) continue;
                string tmp=t[1];
                For(j,0,lens-1)
                    tmp[st+j]=s[2][i][j];
                if(tmp==t[2]) ans++;
            }
        }
        cout<<ans<<'\n';
    }
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);

    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }

    return 0;
}
/*
1s
2048

I pay little time on the strings' algorithm, so here comes the result.
*/