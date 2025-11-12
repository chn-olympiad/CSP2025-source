#include<bits/stdc++.h>

using namespace std;

int n, m, k, i;
int a[110];
int f[11][11];

bool cmp(const int &x, const int &y){
    return x > y;
}
inline void dfs(int x, int y, bool b){//b = 0 xia  b = 1 shang
    f[x][y] = a[++i];
    if(f[x][y] == k){
        printf("%d %d\n", y, x);
        return;
    }
    if(!b){
        if(x == n)
            dfs(x, y + 1, 1);
        else
            dfs(x + 1, y, 0);
    }else{
        if(x == 1)
            dfs(x, y + 1, 0);
        else
            dfs(x - 1, y, 1);
    }
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n * m; i++)
        scanf("%d", &a[i]);
    k = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    dfs(1, 1, 0);
    return 0;
}
