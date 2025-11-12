# include <bits/stdc++.h>
using namespace std;
int n,m,ans;
bool b[505],d[505];
int a[505];
int c[505];

void dfs(int step){
    if (step > n){
        int cnt = 0;
        for (int i=1;i<=n;i++){
            if (cnt >= a[c[i]]){
                cnt++;
                continue;
            }
            if (b[i] == false){
                cnt++;
            }
        }
        if (n-cnt < m) return ;
        ans++;
        ans %= 998244353;
        return ;
    }
    for (int i=1;i<=n;i++){
        if (d[i]) continue ;
        c[step] = i;
        d[i] = 1;
        dfs(step+1);
        d[i] = 0;
    }
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >>n >> m;
    for (int i=1;i<=n;i++){
        char c;
        cin >> c;
        if (c == '1'){
            b[i] = 1;
        }
    }

    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    if (m == n){
        sort(a+1,a+n+1);
        int cnt = 0;
        for (int i=1;i<=n;i++){
            if (cnt >= a[i]){
                cout << 0;
                return 0;
            }
            if (b[i] == false){
                cnt++;
            }
        }
    }

    dfs(1);
    cout << ans;
}
