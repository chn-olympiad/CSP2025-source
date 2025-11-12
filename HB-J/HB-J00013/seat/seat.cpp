#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x[109] = {},ansl;
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> x[i];
    }
    int xl = x[1];
    sort(x + 1,x + 1 + n * m,greater<int>());
    for(int i = 1;i <= n * m;i++){
        if(x[i] == xl){
            ansl = i;
            break;
        }
    }
    if(ansl % n == 0){
        cout << ansl / n << ' ';
        if((ansl / n) % 2 == 0){
            cout << 1;
        } else {
            cout << n;
        }
    } else {
        cout << ansl / n + 1 << ' ';
        if((ansl / n + 1) % 2 == 0){
            cout << n - (ansl % n) + 1;
        } else {
            cout << ansl % n;
        }
    }
    return 0;
}
