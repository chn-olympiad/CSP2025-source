#include<bits/stdc++.h>
using namespace std;

const int MAXN = 15;
int n, m, a[MAXN * MAXN], id[MAXN * MAXN];
pair<int, int> b[MAXN * MAXN];

void dfs(int x, int y, int num){
    if(num == n * m + 1) return;
    b[num] = {x, y};
    if((x == n && (y & 1)) || (x == 1 && !(y & 1))) dfs(x, y + 1, num + 1);
    else if(y & 1) dfs(x + 1, y, num + 1);
    else dfs(x - 1, y, num + 1);
}

signed main(){
    freopen("seat.in", "r", stdin), freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m; for(int i = 1; i <= n * m; ++i) cin >> a[i], id[i] = i;
    dfs(1, 1, 1);
    sort(id + 1, id + n * m + 1, [](int p, int q){ return a[p] > a[q]; });
    for(int i = 1; i <= n * m; ++i) if(id[i] == 1){
        return cout << b[i].second << ' ' << b[i].first, 0;
    }

    return 0;
}