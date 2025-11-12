#include<bits/stdc++.h>
using namespace std;
inline bool cmp(const int &a, const int &b) {
    return a > b;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, len, s, rank, h, w;
    scanf("%d%d", &n, &m);
    len = n * m;
    vector<int> a(len);
    for (int i = 0; i < len; i++)
        scanf("%d", &a[i]);
    s = a[0];
    sort(a.begin(), a.end(), cmp);
//    for (int b : a)
//        printf("%d ", b);
    rank = upper_bound(a.begin(), a.end(), s, cmp) - a.begin();
//    printf("\n%d\n", rank);
    w = (rank) % (2 * n), h = (rank - 1) / n + 1;
//    printf("%d %d", h, w);
    if (w == 0) w = 1;
    if (w > n) w = 2 * n - w + 1;
    printf("%d %d", h, w);
    return 0;
}