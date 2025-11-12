#include <iostream>
#include <algorithm>
using namespace std;
struct seat
{
    int id, score;
} a[105], b[12][12];
bool cmp(seat x, seat y)
{
    return x.score > y.score;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i].score;
        a[i].id = i;
    }
    sort(a + 1, a + n * m + 1, cmp);
    int j = 1, k = 1;
    for (int i = 1; i <= n * m; i++)
    {
        b[j++][k] = a[i];
        if (j > n) {
            j = 1, k++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (b[i][j].id == 1) {
                if (j % 2 == 0) {
                    i = n - i + 1;
                }
                cout << j << ' ' << i;
                return 0;
            }
        }
    }
}