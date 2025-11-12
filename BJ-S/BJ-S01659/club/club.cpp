#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[100001][4];
ll dfs(ll x,ll b,ll c,ll d){
    if(x > n)return 0;
    ll ret = 0;
    if(b < n / 2){
        ret = max(ret,dfs(x + 1,b + 1,c,d) + a[x][1]);
    }
    if(c < n / 2){
        ret = max(ret,dfs(x + 1,b,c + 1,d) + a[x][2]);
    }
    if(d < n / 2){
        ret = max(ret,dfs(x + 1,b,c,d + 1) + a[x][3]);
    }
    return ret;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll t;
    cin >> t;
    while(t--){
        cin >> n;
        for(ll i = 1; i <= n; i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        cout << dfs(1,0,0,0) << "\n";
    }
    return 0;
}
