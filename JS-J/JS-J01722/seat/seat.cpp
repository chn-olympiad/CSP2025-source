#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int arr[105];
int seat[15][15];

bool cmp(int a,int b)
{
    return a > b;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++)
    {
        cin >> arr[i];
    }
    int ans = arr[1];
    sort(arr + 1,arr + 1 + n * m,cmp);
    int tot = 0;
    for(int j = 1;j <= m;j++)
    {
        if(j % 2 == 1)
        {
            for(int i = 1;i <= n;i++)
            {
                tot++;
                seat[i][j] = arr[tot];
                if(seat[i][j] == ans)
                {
                    cout << j << " " << i << '\n';
                    return 0;
                }
            }
        }
        if(j % 2 == 0)
        {
            for(int i = n;i >= 1;i--)
            {
                tot++;
                seat[i][j] = arr[tot];
                if(seat[i][j] == ans)
                {
                    cout << j << " " << i << '\n';
                    return 0;
                }
            }
        }
    }
    return 0;
}
