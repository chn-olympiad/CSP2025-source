#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5E3 + 5;
int ans;
int n;
int a[MAXN];

void dfs(int id, ll sum, ll num){

    if(id == n) return;

    if(num >= 2 && id < n - 1){
        int x = lower_bound(a + id + 1, a + n, sum) - a - 1;
        ans += x - id;
        cout << x << ' ';
        cout << ans << '\n';
    }

    dfs(id + 1, sum, num);
    dfs(id + 1, sum + a[id + 1], num + 1);

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;

    for(int i = 0; i < n; i++ ) cin >> a[i];
    sort(a, a + n);

    dfs(-1, 0, 0);

    cout << ans;

    return 0;

}
