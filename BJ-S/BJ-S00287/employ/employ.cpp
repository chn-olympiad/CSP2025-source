#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans;
char s[19];
ll c[19],vis[19],now[19];
void solve(ll u){
    if(u==n+1){
        ll sum=0;
        ll val=0;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='0' || sum>=c[now[i]]) sum++;
            else val++;
        }
        if(val>=m) ans++;
        //cout <<val <<" ";
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            now[u]=i;
            vis[i]=1;
            solve(u+1);
            vis[i]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >>n >>m;
    cin >>(s+1);
    for(int i=1;i<=n;i++) cin >>c[i];
    solve(1);
    cout <<ans;
    return 0;
}
