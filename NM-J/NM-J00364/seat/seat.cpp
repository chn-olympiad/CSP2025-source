#include <bits/stdc++.h>

using namespace std;

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    int chj[110];
    for(int i = 0; i < n * m; i++)
    {
        cin >> chj[i];
    }
    int xcj = chj[0];
    sort(chj, chj + n * m, cmp);
    int zw[15][15];
    int j = 0;
    int h2 = 0;
    bool pd = true;
    for(int l = 0; l < m; l++)
    {
        for(int h = h2; h < n; h)
        {
            zw[h][l] = chj[j];
            j++;
            if(pd)
            {
                h++;
                h2++;
            }
            else if(!pd)
            {
                h--;
                h2--;
            }
        }
        pd = !pd;
        j++;
    }
//    for(int i = 0; i < n; i++)
//    {
//        for(int k = 0; k < m; k++)
//        {
//            cout << zw[i][k] << ' ';
//        }
//        puts("");
//    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(zw[i][j] == xcj)
            {
                cout << j + 1 << ' ' << i + 1<< '\n';
                return 0;
            }
        }
    }
    if(chj[(n - 1) * (m - 1)] == xcj)
    {
        cout << m << ' ' << n;
    }
    else if(n == 1 && m == 1)
    {
        cout << 1 << ' ' << 1;
    }
    else
    {
        cout << m / 2 << ' ' << n / 2;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

