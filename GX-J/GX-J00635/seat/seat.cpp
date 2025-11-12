#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int b[n*m] = {0};
    for(int i = 0; i < n*m;i++)
    {

        cin >> b[i];
    }
    int r = b[0];


    int a[n][m];
    for(int i = 0; i < n*m;i++)
    {
        for(int p = 0; p < n*m;p++)
        {
            if(b[i] > b[p])
                swap(b[i],b[p]);
        }
    }

    int cnt = 0;
    for(int i = 0; i < m; i++)
    {
        if(i % 2 == 0)
        {
            for(int p = 0; p < n; p++)
            {
                a[p][i] = b[cnt];
                cnt++;
            }
        }
        else
        {
            for(int p = n-1; p >= 0; p--)
            {
                a[p][i] = b[cnt];
                cnt++;

            }
        }

    }
    for(int i = 0; i < n;i++)
    {
        for(int p = 0; p < m; p++)
        {
            if(a[i][p] == r)
            {
                cout << p+1 << " " << i+1;
            }

        }
    }


    return 0;
}



