#include <bits/stdc++.h>
using namespace std;
const int maxn = 1050;
int n, m, c, r;
int a[maxn];
int b[maxn];
int cnt;
int st(int a, int b){
    return a > b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a + 1, a + n * m + 1, st);
    for(int i = 1; i <= n * m; i++){
        if(a[i] == b[1]){
            cnt = i;
        }
    }
    int zs = 0;
    for(int i = 1; i <= m; i++){
        if(cnt - 2 * n > 0){
            cnt -= 2 * n;
            zs ++;
        }else{
            if(cnt > n){
                c = i + zs * 2 + 1;
                r = 2 * n - cnt + 1;
                break;
            }else{
                c = 1 + zs * 2;
                r = cnt;
                break;
            }
        }
    }
    cout << c << " " << r;




    return 0;
}
