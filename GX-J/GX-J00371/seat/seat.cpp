#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n,m;
    cin >> n >> m;
    int a[n*m];
    for(int i = 0;i < n*m;i++)
        cin >> a[i];

    int js = 0;
    for(int i = 1;i < n*m;i++)
        if(a[i] > a[0])
        js++;
    js++;
    bool y = true;
    for(int i = 0;i < m;i++)
    {
        if(y == false)
            break;
        if(i % 2 == 1)
        {
            for(int j = n-1;j >= 0;j--)
            {
                js--;
                if(js == 0)
                {
                    cout << i+1 << " " << j+1;
                    y = false;
                    break;
                }
            }
        }
        else
        {
            for(int j = 0;j < n;j++)
            {
                js--;
                if(js == 0)
                {
                    cout << i+1 << " " << j+1;
                    y = false;
                    break;
                }
            }
        }
    }
    return 0;
}
