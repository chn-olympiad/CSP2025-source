/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][5], p[5];
long long ans, tans;
void dfs(int x) {
    if(x>n) {
        ans = max(ans, tans);
        return;
    }
    for(int i=1;i<=3;i++) {
        if(p[i]>=n/2)
            continue;
        tans+=a[x][i];
        p[i]++;
        dfs(x+1);
        tans-=a[x][i];
        p[i]--;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--) {
        ans = tans = 0;
        p[1] = p[2] = p[3] = 0;
        cin >> n;
        for(int i=1;i<=n;i++)
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        dfs(1);
        cout << ans << '\n';
    }
    return 0;
}
