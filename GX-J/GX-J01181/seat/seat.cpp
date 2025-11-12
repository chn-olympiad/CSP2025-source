#include <bits/stdc++.h>

using namespace std;

bool ps(int a , int b)
{
    if(a > b)
        return true;
    else
        return false;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n , m;
    cin >> n >> m;
    int a[n * m];

    int jz;
    cin >> jz;
    a[0] = jz;
    for(int i = 1 ; i < n * m ; i++)
        cin >> a[i];
    sort(a , a + n * m , ps);

    int cnt = 0;
    for(int i = 0 ; i < m ; i++)
    {
        if(i % 2 == 0)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(a[cnt] == jz)
                {
                    cout << i + 1 << ' ' << j + 1;
                    return 0;
                }
                cnt++;
            }
        }
        else
        {
            for(int j = n - 1 ; j >= 0 ; j--)
            {
                if(a[cnt] == jz)
                {
                    cout << i + 1 << ' ' << j + 1;
                    return 0;
                }
                cnt++;
            }
        }
    }

    return 0;
}
