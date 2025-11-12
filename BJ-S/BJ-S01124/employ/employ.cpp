#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int mod = 998244353;
char s[N];
int a[N];
int n, m;
int ans;
void dfs(int now, int cnt, int lose){
    if(cnt >= m && now == n){
        ans++;
        return;
    }
    for(int i = now;i <= n;i++){
        if(a[i] > lose){
            if(s[i] == '1'){
                dfs(i + 1, cnt + 1, lose);
            }
            else dfs(i + 1, cnt, lose + 1);
            //cout << now << " " << cnt << "\n";
        }
    }
    return;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> s;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    dfs(1, 0, 0);
    cout << ans << "\n";
    return 0;
}
