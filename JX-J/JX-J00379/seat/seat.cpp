#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n, m, a[105], b, c[105];
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    b = a[1];
    sort (a + 1, a + n * m + 1);
    for (int i = n * m; i >= 1; i--) c[n * m - i + 1] = a[i];
    for (int i = 1; i <= m * n; i++){
        if (c[i] == b){
            if ((i / m + 1) % 2 == 1 and i % n != 0) cout << i / n + 1 << " " << i % n;
            else if ((i / m + 1) % 2 == 0 and i % n == 0) cout << i / n << " " << n;
            else if ((i / m + 1) % 2 == 0 and i % n != 0) cout << i / n + 1 << " " << m - i % n + 1;
            else cout << i / n << " " << 1;
        }
    }
    return 0;
}
