#include <bits/stdc++.h>
using namespace std;
struct Student { int a, id; } a[105];
int n, m, id;
bool cmp(Student a, Student b) { return a.a > b.a; }
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++) cin >> a[i].a, a[i].id = i;
    sort(a + 1, a + n * m + 1, cmp);
    for(int i = 1; i <= n * m; i++) if(a[i].id == 1)
    {
        id = i;
        break;
    }
    int mm = (id - 1) / n + 1, nn = id - (mm - 1) * n;
    if(mm % 2 == 0) nn = n - nn + 1;
    cout << mm << ' ' << nn;
    return 0;
}
