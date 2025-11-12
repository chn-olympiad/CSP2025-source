#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int a[N], n, m;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i ++){
        cin >> a[i];
    }
    int flag = a[1];
    sort(a + 1, a + 1 + n * m);
    reverse(a + 1, a + 1 + n * m);
    for(int i = 1; i <= n * m; i ++){
        if(a[i] == flag){
            flag = i;
            break;
        }
    }
    int c;
    if(flag % m == 0){
        cout << (flag / m) << " ";
        c = flag / m;
    }else{
        cout << (flag / m) + 1 << " ";
        c = (flag / m) + 1;
    }
    if(c % 2 == 1){
        cout << flag - (c - 1) * m;
    }else{
        cout << n - (flag - (c - 1) * m) + 1;
    }

    return 0;
}
