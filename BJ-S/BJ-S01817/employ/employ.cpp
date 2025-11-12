#include<bits/stdc++.h>
using namespace std;
int n,m,ans,mod = 998244353;
string s;
int c[505];
bool vis[505];
void dfs(int step,int cnt){
    if(step == n + 1){
        if(n - cnt >= m){
            ans = (ans + 1) % mod;
        }
        return;
    }
    for(int i = 1;i <= n;i++){
        if(vis[i])continue;
        vis[i] = 1;
        if(s[step - 1] == '0'){
            cnt ++;
        }
        else if(cnt >= c[i]){
            cnt++;
        }
        dfs(step + 1,cnt);
        vis[i] = 0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 1;i <= n;i++)cin >> c[i];
    dfs(1,0);
    cout << ans;
    return 0;
}
