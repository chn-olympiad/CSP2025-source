#include <bits/stdc++.h>
using namespace std;

bool flag[10005];
int n, m, k, v[10005], ca[10][15], cur[10005], res = 0x3f3f3f3f, tmp;
vector<int> s[10005];

void dfs(int c, int cnt) {
    cur[cnt] = c;
    if (cnt == n) {
        for (int i = 1; i < cnt; i++) {
            tmp += v[cnt];
        }
        res = min(res, tmp);
        return;
    }
    for (int i = 0; i < s[c].size(); i++) {
        int curCity = s[c][i];
        if (!flag[curCity]) {
            flag[curCity] = true;
            cnt++;
            dfs(s[c][i], cnt);
            flag[curCity] = false;
            cnt--;
        }
    }
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> m >> k; // n = city, m = road
    for (int i = 1; i <= m; i++) {
        int x, y, val;
        cin >> x >> y >> v[i];
        s[x].push_back(y);
        s[y].push_back(x);
    }
    dfs(1, 1);
    cout << res << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}