#include<bits/stdc++.h>
using namespace std;
int a[101];
int zw[11][11];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++)
    {
        cin >> a[i];
    }
    int t = a[1];
    int xb = 0;
    sort(a+1,a+n*m+1);
    for(int j = m;j >= 1;j--)
    {
        if(j % 2 == 1)
        {
            for(int i = n;i >= 1;i--)
            {
                xb++;
                if(t == a[xb])
                {
                    cout << j << " " << i;
                    return 0;
                }
            }
        }
        else
        {
            for(int i = 1;i <= n;i++)
            {
                xb++;
                if(t == a[xb])
                {
                    cout << j << " " << i;
                    return 0;
                }
            }
        }
    }
    return 0;
}
