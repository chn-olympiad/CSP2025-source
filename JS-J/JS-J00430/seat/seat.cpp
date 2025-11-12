#include<bits/stdc++.h>
using namespace std;
int n, m, t, a[105], mb, xb, seat, hang, lie, op;
int main(){
    freopen("seat.in", "r",stdin);
    freopen("seat.out", "w",stdout);
    cin >> n >> m;
    t = n * m;
    for(int i = 1;i <= t;i++){
        cin >> a[i];
    }
    mb = a[1];
    sort(a + 1, a + t + 1);
    for(int i = t;i >= 1;i--){
        if(a[i] == mb){
            xb = (t - i + 1);
            break;
        }
    }
    lie = 1, hang = 1;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n - 1;j++){
            if(op == xb - 1){
                cout << lie << " " << hang;
                return 0;
            }
             if(i % 2 == 1) hang++;
            else hang--;
            op++;
        }
        if(op == xb - 1){
            cout << lie << " " << hang;
            return 0;
        }
        lie++;
        op++;
    }
    return 0;
}
