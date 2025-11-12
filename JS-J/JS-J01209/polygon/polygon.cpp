#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[50005], ans;
bool cmp(int x, int y){
    return x > y;
}
void dfs(int x, int sum, int maxn, int cnt){
    if(x > n){
        if(sum > 2 * maxn && cnt > 2){
            ans++;
        }
        return;
    }
    int tmp = maxn;
    if(maxn < a[x]) maxn = a[x];
    dfs(x + 1, sum + a[x], maxn, cnt + 1);
    dfs(x + 1, sum, tmp, cnt);
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    dfs(1, 0, 0, 0);
    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
