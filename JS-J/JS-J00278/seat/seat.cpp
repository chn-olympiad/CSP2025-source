#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], pos, c, r;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j)
            scanf("%d", a + (m * (i - 1) + j));
    sort(a + 2 , a + m * n + 1);
    pos = m * n - (upper_bound(a + 2, a + m * n + 1, a[1]) - a) + 2;
    c = (pos + n - 1) / n;
    if(c % 2) r = pos - (c - 1) * n;
    else r = c * n - pos + 1;
    printf("%d %d\n", c, r);
    fclose(stdin);
    fclose(stdout);
}
