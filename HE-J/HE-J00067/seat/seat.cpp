#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[50][50];
int b[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y;
    cin >> x >> y;
    int n=x*y;
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
    }
    int p=b[1];
    sort(b+1,b+1+n);
    int s=n+1;
    for(int j=1;j<=y/2;j++)
    {
        for(int i=1;i<=x;i++)
        {
            s--;
            if(b[s]==p)
            {
                cout << j << ' ' << i;
            }
        }
        for(int i=x;i>=1;i--)
        {
            s--;
            if(b[s]==p)
            {
                cout << j+1 << ' ' << i;
            }
        }
    }
    if(y%2!=0)
    {
        for(int i=1;i<=x;i++)
        {
            s--;
            if(b[s]==p)
            {
                cout << y << ' ' << i;
            }
        }
    }
    return 0;
}
