#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define For(x,l,r) for(ll x=l;x<=r;++x)
#define Rof(x,l,r) for(ll x=r;x>=l;--x)
#define pb push_back

const int N = 505, mod = 998244353;

int n,m;
int s[N];
int c[N];
int ans;
bool vis[N];
int p[N];
bool check(){
    int in=0,out=0;
    For(i,1,n){
        if(s[i]==0||out>=c[p[i]]){
            out++;
        }
        else in++;
    }
    return in>=m;
}
void dfs(int i){
    if(i>n){
        ans+=check();
        return ;
    }
    For(j,1,n){
        if(vis[j]) continue;
        vis[j]=1;
        p[i]=j;
        dfs(i+1);
        vis[j]=0;
    }
}

void solve(){
    cin>>n>>m;
    For(i,1,n){
        char x;cin>>x;
        s[i]=x-'0';
    }
    For(i,1,n) cin>>c[i];
    dfs(1);
    cout<<ans<<'\n';
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
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
512

horrible counting problem
*/