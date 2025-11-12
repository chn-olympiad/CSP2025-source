#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    // program
    int n, m, R;
    cin >> n >> m;
    vector <int> a(n * m, 0);
    for(int i = 0;i < m * n;i++) cin >> a[i];
    R = a[0];
    sort(a.begin(), a.end()); // 从低到高 
    int rak = n * m - (lower_bound(a.begin(), a.end(),R) - a.begin());
//    cout << rak << endl;
    int col = (rak - 1 <= 0 ? 1 : (rak - 1) / n + 1);
    int row;
    if(col & 1) row = (rak - 1) % m + 1;
    else row = m - ((rak - 1) % m);
    cout << col << ' ' << row << endl;
    return 0;
    // 需要对拍 
}
