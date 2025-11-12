#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100005];
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n * m;i ++){
        cin >> a[i];
    }
    int x = a[1];
    sort(a + 1, a + m * n + 1);
    for (int i = 1;i <= m * n / 2;i ++) swap(a[i], a[m * n - i + 1]);
    for (int i = 1;i <= n;i ++){
        for (int j = 1;j <= m;j ++){
            if (a[(i - 1) * n + j] == x){
                cout << i << " " << j * (i % 2) + (m - j + 1) * (!(i % 2));
                return 0;
            }
        }
    }
    return 0;
}
