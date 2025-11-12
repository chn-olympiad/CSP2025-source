#include <bits/stdc++.h>
using namespace std;

int a[1010], b[1010][1010];
int n, m, ans;
int sum = 1, num = 0;

int cmp(int x, int y){
    return x > y;
}

int main(){

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    ans = a[1];
    sort(a + 1, a + (n * m) + 1, cmp);
    for(int i = 1; i <= n * m; i++){
        if(sum % 2 == 1 && num < n){
            b[++num][sum] = a[i];
        }
        else if(sum % 2 == 0 && num > 1){
            b[--num][sum] = a[i];
        }
        else if((sum % 2 == 1 && num == n) || (sum % 2 == 0 && num == 1)){
            b[num][++sum] = a[i];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
           if(b[i][j] == ans){
                cout << j << " " << i;
                return 0;
            }

        }
    }
}
