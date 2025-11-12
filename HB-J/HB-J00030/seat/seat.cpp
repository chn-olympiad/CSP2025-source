#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int n, m, graph[N][N], arr[N], g, num;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;

    int sum = 1;

    for(int i = 1;i <= m;++ i)
    {
        if(i % 2 == 1)
        {
            for(int j = 1;j <= n;++ j)
            {
                graph[j][i] = sum;
                sum ++;
            }
        }
        else
        {
            for(int j = n;j >= 1;-- j)
            {
                graph[j][i] = sum;
                sum ++;
            }
        }
    }

    for(int i = 1;i <= n * m;++ i)
    {
        cin >> arr[i];
    }

    g = arr[1];

    sort(arr + 1, arr + 1 + n * m, cmp);

    for(int i = 1;i <= n * m;++ i)
    {
        if(g == arr[i])
        {
            num = i;
            break;
        }
    }

    for(int i = 1;i <= n;++ i)
    {
        for(int j = 1;j <= m;++ j)
        {
            if(num == graph[i][j])
            {
                cout << j << ' ' << i;
                return 0;
            }
        }
    }

    return 0;
}
