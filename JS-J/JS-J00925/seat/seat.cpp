#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 5;

int arr[MAXN];
int idx;

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n * m; ++i)
    {
        cin >> arr[i];
    }

    arr[0] = arr[1];

    sort(arr + 1, arr + n * m + 1, cmp);

    for (int i = 1; i <= n * m; ++i)
    {
        if (arr[i] == arr[0])
        {
            idx = i;
            break;
        }
    }

    int i = 1, j = 1;

    for (int k = 1; k <= n * m; ++k)
    {
        if (k == idx) 
        {
            cout << j << " " << i << '\n';
            return 0;
        }

        if (i == n)
        {
            if (j % 2) ++j;
            else --i;
        } else if (i == 1)
        {
            if (j % 2) ++i;
            else ++j;
        } else 
        {
            if (j % 2) ++i;
            else --i;
        }
    }

    return 0;
}