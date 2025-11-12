#include <bits/stdc++.h>

//RP++

using namespace std;

const int MAXN = 1e3 + 5;



int n, m;
int a[MAXN];
int seat[MAXN][MAXN];

int R;
int ptr;

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);


    cin >> n >> m;

    int num = n * m;

    for(int i = 1; i <= num; i++)
    {
        cin >> a[i];
    }

    R = a[1];

    sort(a + 1, a + 1 + num, cmp);

    // for(int i = 1; i <= num; i++)
    // {
    //     if(a[i] == R)
    //     {
    //         idx = i;
    //     } 
    // }

    // for(int i = 1; i <= num; i++)
    // {
    //     cout << a[i] << " ";
    // }

    for(int i = 1; i <= m; i++)
    {
        if(i & 1)
        {
            for(int j = 1; j <= n; j++)
            {
                seat[j][i] = a[++ptr];
            }
        }
        else
        {
            for(int j = n; j >= 1; j--)
            {
                seat[j][i] = a[++ptr];
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(seat[i][j] == R)
            {
                cout << j << " " << i;
                return 0;
            }
        }
    }

    return 0;
}