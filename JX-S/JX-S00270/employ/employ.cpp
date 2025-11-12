#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN];
int choice[MAXN];
int sum = 0;
int n, m;
bool vis[MAXN];
int c[MAXN];
string zt;
int result = 0;
void check() {
    int ssum = 0;
    int no = 0;
    for(int i = 1; i <= n; i++) {
            //cout << choice[i] << ' ' << c[choice[i]] << ' ' << no << ' ' << zt[i - 1] << endl;
        if(no >= c[choice[i]]) {
            no++;
            continue;
        }
        if(zt[i - 1] == '0') {
            no++;
            continue;
        }
        ssum++;
    }
    //cout << ssum << endl;

    if(ssum >= m) {
        result++;
    }
}
void dfs(int x) {
    if(x == n + 1) {
        //jie suan
        check();
        return ;
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            vis[i] = 1;
            choice[x] = i;
            dfs(x + 1);
            vis[i] = 0;
        }
        sum++;
    }
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    //4:30
    //zui hou 90 min
    cin >> n >> m;
    cin >> zt;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
//cout << endl;
    dfs(1);

    cout << result << endl;
    return 0;
}
