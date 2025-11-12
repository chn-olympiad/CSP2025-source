#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x, int y){
    return x > y;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n*m; i++) cin >> a[i];
    int a1 = a[1];
    sort(a+1, a+n*m+1, cmp);
    for(int i = 1; i <= n*m; i++){
        if(a[i] == a1){
            int k = (i+n-1)/n, w = (i-1)%n+1;
            cout << k << ' ';
            if(k % 2 == 1){
                cout << w;
            }
            else cout << n-w+1;
            return 0;
        }
    }
    return 0;
}
