#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
const ll mod = 998244353;
ll n,m;
string s;
int a[510];
bool vis[510];
ll ans;
void Dfs(int cc,int z){
    if(n - z < m){
        return;
    }
    if(cc == n + 1){
        if(n - z >= m){
            ans ++;
        }
        ans %= mod;
        return;
    }
    for(int i = 1;i <= n;i ++){
        if(!vis[i]){
            vis[i] = 1;
            if(z >= a[i] || s[cc] == '0'){
                Dfs(cc + 1,z + 1);
            }
            else{
                Dfs(cc + 1,z);
            }
            vis[i] = 0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    Dfs(1,0);
    cout << ans << endl;
    return 0;
}