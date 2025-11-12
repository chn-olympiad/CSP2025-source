#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n, m;
    cin >> n >> m;
    int score, cnt = 1;
    cin >> score;
    for (int i = 1; i < n * m; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > score) cnt++;
    }
    int row, col;
    col = (cnt + n - 1) / n;
    if (col % 2) {
        row = (cnt - 1) % n + 1;
    } else {
        row = n - (cnt - 1) % n;
    }
    cout << col << ' ' << row << endl;
    return 0;
}
