#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int n, m, score1;
const int MAXN = 11, MAXM = 11;
int map[MAXN][MAXM], scores[MAXN * MAXM];

signed main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m >> score1;
    scores[0] = score1;
    for (int i = 1; i < n * m; i++)
    {
        cin >> scores[i];
    }
    sort(scores, scores + n * m);
    int k = n*m-1;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2)
        {
            for (int j = 1; j <= m; j++)
            {
                map[j][i] = scores[k--];
            }
        }
        else
        {
            for (int j = m; j > 0; j--)
            {
                map[j][i] = scores[k--];
            }
        }
        for (int j = 1; j <= m; j++)
        {
            if (map[j][i] == score1)
            {
                cout << i << ' ' << j << endl;
                return 0;
            }
        }
    }
    return 0;
}