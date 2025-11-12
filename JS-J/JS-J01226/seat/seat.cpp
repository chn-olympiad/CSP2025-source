#include <bits/stdc++.h>
using namespace std;
int n, m, num;
int a[105] = {};
void solve(int t, int i, int j){
    if (t == num) {
        cout << j << ' ' << i;
        return;
    }else if (j%2 == 1 && i == n) solve(t+1, i, j+1);
    else if (j%2 == 0 && i == 1) solve(t+1, i, j+1);
    else if (j%2 == 1) solve(t+1, i+1, j);
    else if (j%2 == 0) solve(t+1, i-1, j);
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n*m; i++){
        cin >> a[i];
    }
    int s = a[1];
    sort(a+1, a+n*m+1);
    for (int i = 1; i <= n*m; i++){
        if (a[i] == s) {
            num = n*m-i+1;
            break;
        }
    }
    solve(1, 1, 1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
