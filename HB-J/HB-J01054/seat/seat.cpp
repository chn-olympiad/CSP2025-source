#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[1010];
int g[100][100];
bool cmp(int a, int b){
    return a > b;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int z = n*m;
    for(int i = 1; i <= z; i++){
        cin >> a[i];
    }
    int R = a[1];
    int k = 1;
    sort(a+1, a+z+1, cmp);
    g[1][1] = a[1];
    int x = 1, y = 1;
    int now = 1;
    while(now <= z){
        if(y%2 == 1 && x < n){
            g[x+1][y] = a[++k];
            x++;
            now++;
            continue;
        }
        if(x == n && y%2 == 1){
            g[x][y+1] = a[++k];
            y++;
            now++;
            continue;
        }
        if(x > 1 && y%2 == 0){
            g[x-1][y] = a[++k];
            x--;
            now++;
            continue;
        }
        if(x == 1 && y%2 == 0){
            g[x][y+1] = a[++k];
            y++;
            now++;
            continue;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(g[i][j] == R){
                cout << j << " " << i;
                return 0;
            }
        }
    }
    return 0;
}
