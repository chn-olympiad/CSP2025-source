#include <bits/stdc++.h>
using namespace std;
int a[505], vis[505], cnt = 0, b[505], ans = 0;
int n, m;
string s;
void dfs(int x){
    if(x >= n){
        int cnt1 = 0;
        for(int i = 1; i <= cnt; i ++){
            if(s[i-1] == '0'){
                cnt1 ++;
            }else if(a[b[i]] <= cnt1){
                cnt1 ++;
            }
            //cout << b[i] << " ";
        }
        //cout << endl;
        //cout << cnt1 << endl;

        if(n - cnt1 >= m){
            ans ++;
        }
        return;
    }
    for(int i = 1; i <= n; i ++){
        if(vis[i] == 0){
            vis[i] = 1;
            b[++cnt] = i;
            dfs(x+1);
            vis[i] = 0;
            b[cnt] = 0;
            cnt --;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    int su = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        if(a[i]!= 0){
            su ++;
        }
    }
    if(m == 1){
        cout << su;
        return 0;
    }
    dfs(0);
    cout << ans;
    return 0;
}
