#include<bits/stdc++.h>
#define mem(a, v) memset(a, v, sizeof(a))

using namespace std;

const int maxn = 10 + 10;

int n, m;
pair<int, int> a[maxn * maxn];

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n * m; i++){
        scanf("%d", &a[i].first), a[i].second = i;
    }
    sort(a + 1, a + n * m + 1, greater<>());
    int pos = 0;
    for (int i = 1; i <= n * m; i++){
        a[i].second == 1 && (pos = i);
    }
    const int tmp = (pos - 1) % n + 1, val = (pos + n - 1) / n;
    printf("%d %d", val, val & 1 ? tmp : n - tmp + 1);

return 0;
}