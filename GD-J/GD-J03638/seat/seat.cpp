#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int mapp[11][11], a[110];

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    memset(mapp, 0, sizeof(mapp));
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    int xm = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int k = 1;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            
            if (i % 2 == 1)
            {
                mapp[i][j] = a[k++];
                if (mapp[i][j] == xm)
                {
                    cout << i << ' ' << j << endl;
                    return 0;
                }
            }
            else
            {
                mapp[i][m - j + 1] = a[k++];
                if (mapp[i][m - j + 1] == xm)
                {
                    cout << i << ' ' << m - j + 1 << endl;
                    return 0;
                }
            }
        }
    }


}