#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 15;
int a[maxn*maxn];
int n, m, all;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    all = n * m;
    for (int i=1; i<=n*m; i++) cin >> a[i];
    int x = a[1];
    sort(a+1, a+all+1);
    int idx = lower_bound(a+1, a+all+1, x) - a;
    idx = all - idx;

    int c = idx / n;
    int r = idx % n;
    if (c % 2 == 1) r = n - r - 1;

    cout << c+1 << " " << r+1;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
