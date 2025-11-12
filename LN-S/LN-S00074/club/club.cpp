#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define x first 
#define y second 

using namespace std;
typedef pair<int, int> PII;

const int N = 100005;

int a[N][3];
int n;
vector<int> l[3];
PII temp[3];

void solve(){
    for (int c = 0; c < 3; c ++ ) l[c].clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) 
        for (int c = 0; c < 3; c ++ ) scanf("%d", &a[i][c]);

    int ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        for (int c = 0; c < 3; c ++ ) temp[c] = {a[i][c], c};
        sort(temp, temp + 3);
        ans += temp[2].x, l[temp[2].y].push_back(temp[2].x - temp[1].x);
    }
    for (int c = 0; c < 3; c ++ ) {
        if (l[c].size() > (n >> 1)) {
            sort(l[c].begin(), l[c].end());
            for (int i = 0; i < l[c].size() - (n >> 1); i ++ ) ans -= l[c][i];
            break;
        }
    }
    printf("%d\n", ans);
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T -- ) solve();
}