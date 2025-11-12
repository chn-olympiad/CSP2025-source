#include <iostream>
using namespace std;
int n, m;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int x;
    cin >> x;
    int cnt = 0;
    for(int i = 2;i <= n * m;i++){
        int k;
        cin >> k;
        if(k > x) cnt++;
    }
    int p = 1, q = 1, fl = 1;
    while(cnt--){
        q += fl;
        if(q == 0){
            fl *= -1;
            q = 1;
            p++;
        }
        if(q == n + 1){
            fl *= -1;
            q = n;
            p++;
        }
    }
    cout << p << ' ' << q;
    return 0;
}
