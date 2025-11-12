#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[505];
bool vis[505];
int ans[505];
int res = 0;
int cnt = 0;
int pas = 0;
void dfs(int x){
    if(x > n){
        cnt = pas = 0;
        for(int i = 0;i < n;i++){
            if(ans[i + 1] <= cnt){continue;}
            if(s[i] == '1'){
                pas++;
                continue;
            }else{
                cnt++;
            }
        }
        if(pas >= m){
            res++;
        }
        return;
    }
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            vis[i] = 1;
            ans[x] = a[i];
            dfs(x + 1);
            vis[i] = 0;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dfs(1);
    cout << res;
    return 0;
}
