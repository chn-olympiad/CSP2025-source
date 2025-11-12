#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
struct node {
    int id, val;
}a[105];
bool cmp(node a, node b) {
    return a.val > b.val;
}
int mp[15][15];
signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++)
        cin >> a[i].val, a[i].id = i;
    sort(a + 1, a + 1 + n * m, cmp);
    int x = 1, y = 1, v = 1, f = 1;
    while(v <= n * m) {
        mp[x][y] = v++;
        if(f == 1) {
            x++;
            if(x > n)
                y++, x--, f = 0;
        } else {
            x--;
            if(x < 1)
                y++, x++, f = 1;
        }
    }
    int nid = -1;

    for(int i = 1; i <= n * m; i++)
        if(a[i].id == 1)
            nid = i;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) 
            if(mp[i][j] == nid)
                return cout << j << ' ' << i << '\n', 0;
}
/*
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ 
*/