#include <bits/stdc++.h>

using namespace std;
const int N = 15;
int n, m;
int score[N*N], board[N][N];
vector<int> res;

// 10 -> brute
// no same

int dir[3][2] = {1, 0, -1, 0, 0, 1};

void dfs(int x, int y, int k){
    if (k == 0) {
        res = {x, y};
        return;
    }
    board[x][y] = 1;
    if (x == 1){
        if (board[x+1][y] == 0) {
            dfs(x+1, y, k-1);
        }
        else {
            dfs(x, y+1, k-1);
        }
    }
    else if (x == n){
        if (board[x-1][y] == 0){
            dfs(x-1, y, k-1);
        }
        else {
            dfs(x, y+1, k-1);
        }
    }
    else{
        if (board[x-1][y] == 0){
            dfs(x-1, y, k-1);
        }
        else {
            dfs(x+1, y, k-1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n*m; i++){
        cin >> score[i];
    }
    int sc = score[1];
    sort(score+1, score+n*m+1, greater<int>());

    int pos;
    for (int i = 1; i <= n*m; i++){
        if (score[i] == sc){
            pos = i;
            break;
        }
    }
    if (n == 1) res = {1, pos};
    else dfs(1, 1, pos-1);
    cout << res[1] << ' ' << res[0];
    return 0;
}
/*3 3
94 95 96 97 98 99 100 93 92
*/
