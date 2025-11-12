#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int dx[] = {1, -1, 0};
int dy[] = {0, 0, 1};
int n, m;
int a[maxn];
int b[maxn];
int seat[maxn][maxn];
int judge[maxn][maxn];
int ii;
int ans = 0;
/*
yangli1:
_______________________________________
3 3
94 95 96 97 98 99 100 93 92
________________________________________
yangli2:
_______________________________________
2 2
98 99 100 97
________________________________________
yangli3:
_________________________________________
2 2
99 100 97 98
_________________________________________

*/
void dfs(int nowx, int nowy) {
    //printf("seat[%d][%d] = a[%d]\n", nowx, nowy, ii);
    //printf("a[%d] = %d\n", ii, a[ii]);
    if(ii == n * m || nowx >= n && nowy >= m) {
        return ;
    }
    seat[nowx][nowy] = a[ii];
    ii++;
    
    for(int i = 0; i < 3; ++i) {
        if(judge[nowx+dx[i]][nowy+dy[i]] != 1 && nowx + dx[i] < n && nowy + dy[i] < m && nowx + dx[i] >= 0 && nowy + dy[i] >= 0){
            //printf("nowx(%d) + dx[%d] = %d , nowy(%d) + dy[%d] = %d\n", nowx, i, nowx+dx[i], nowy, i, nowy+dy[i]);
            judge[nowx][nowy] = 1;
            dfs(nowx+dx[i], nowy+dy[i]);
        }
    }
}
int main() {

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    
    scanf("%d%d", &n, &m);
    int sum = n * m;
    for(int i = 0; i < sum; ++i) {
        scanf("%d", &b[i]);
    }
    ans = b[0];
    sort(b, b + sum);
    for(int i = 0; i < sum; ++i) {
        a[i] = b[sum - i - 1];
    }
    dfs(0, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            //
            //printf("%d i(%d)j(%d)", seat[i][j], j + 1, i + 1);
            if(seat[i][j] == ans){
                printf("%d %d", j + 1, i + 1);
            }
        }
        //
        //cout << endl;
    }
    return 0;
}