#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,ans;
const int MOD = 998244353;
int a[505],p[505];
bool vis[505];
string s;
void dfs(int x){
    if(x==n+1){
        int cnt = 0,c = 0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0' || cnt>=a[p[i]]){
                cnt++;
            }
            else{
                c++;
            }
        }
        if(c>=m){
            ans = (ans+1)%MOD;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            p[x] = i;
            vis[i] = 1;
            dfs(x+1);
            vis[i] = 0;
            p[x] = 0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    s = " "+s;
    bool flag = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(s[i]=='0'){
            flag = 1;
        }
    }
    if(!flag){
        int x = 1;
        for(int i=1;i<=n;i++){
            x = x*i%MOD;
        }
        cout << x;
        return 0;
    }
    dfs(1);
    cout << ans;
    return 0;
}
