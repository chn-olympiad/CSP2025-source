#include <bits/stdc++.h>
using namespace std;

int n;
int cnt;
int a[5005];

void dfs(int x, int num, int dep){
    if(num > 2 * a[x] && dep >= 3){
        cnt++;
    }
    for(int i = x + 1; i <= n; i++){
        num += a[i];
        dep++;
        dfs(i, num, dep);
        num -= a[i];
        dep--;
    }
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    /*if(a[n - 1] == 1){
        for(int i = 2; i <= n; i++){
            int ans = 1;
            for(int j = 1; j <= n - i; j++){
                ans = ans * j;
                ans = ans % 998;
            }
            cnt += ans;
            cnt = cnt % 998;
        }
        cnt = cnt % 353;
        cnt = cnt % 244;
        cout << cnt;
        return 0;
    }*/
    for(int i = 1; i <= n; i++){
        dfs(i, a[i], 1);
        cnt %= 998;
    }
    cnt %= 244;
    cnt %= 353;
    cout << cnt;
    return 0;
}
