#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int sn = n * m;
    int s;
    cin >> s;
    int mc = 0;
    for (int i = 1; i < sn; i++){
        int t;
        cin >> t;
        if (t > s)mc++;
    }
    cout << mc / n + 1 << ' ';
    if (mc / n % 2 == 0){
        cout << mc % n + 1;
    }else{
        cout << n - mc % n;
    }
    return 0;
}
