#include<bits/stdc++.h>
using namespace std;
int n, m, s[1005];
bool cmp(int a, int b){
    return a > b;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n * m;++ i) cin >> s[i];
    int x = s[1];
    sort (s + 1, s + n * m + 1, cmp);
    for (int i = 1;i <= n * m;++ i){
        if (s[i] == x) {
            x = i;
            break;
        }
    }
    int i = 1, cnt = 0;
    for ( ;i <= m; ){
        for (int j = 1;j <= n;++ j){
            cnt ++;
            if (cnt == x){
                cout << i << ' ' << j;
                return 0;
            }
        }
        i ++;
        for (int k = n;k >= 1;-- k){
            cnt ++;
            if (cnt == x){
                cout << i << ' ' << k;
                return 0;
            }
        }
        i ++;
    }
    return 0;
}
