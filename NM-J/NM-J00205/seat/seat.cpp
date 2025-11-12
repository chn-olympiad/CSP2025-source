#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int n, m, score, ans;
int a[105];
inline int getLie(int num) {
    return num % n == 0 ? num / n : num / n + 1;
}

inline int getHang(int num) {
    int origin = num % n == 0 ? n : num % n;
    if (getLie(num) % 2 == 0) {
        return n - origin + 1;
    } else {
        return origin;
    }
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    cin >> score;
    for (int i = 2; i <= n*m; i++) {
        cin >> a[i];
    }
    sort(a+2, a+n*m+1, greater<int>());
    for (int i = 2; i <= n*m; i++) {
        if (a[i] < score) {
            ans = i-1;
            break;
        }
    }
    cout << getLie(ans) << ' ' << getHang(ans);
    return 0;
}
