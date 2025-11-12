#include <iostream>

using namespace std;
int main()
{
    int mn[10][10],a[100],m,n,aa,t;
    cin >> m;
    cin >> n;
    for (int i = 0;i < m*n;i++)
    {
        cin >> a[i];
    }
    aa=a[0];
    for(int i = 1;i != 0;)
    {
        for (int i2 = 1 ;i2 < m*n;i2++)
        {
            if(a[i2]>a[i2-1])
            {
                t=a[i2];
                a[i2]=a[i2-1];
                a[i2-1]=t;
                i2 = 1;
            }
        }
    }
    for (int i1 = 0,s = 0;i1 < m;i1++)
    {
        for(int i2 = 0,pp=0,qq=0;i2 < n;i2++)
        {
            mn[i1][i2] = a[s];
            s++;
        }
    }
    for (int i,x[10];i<=m;i=i+2)
    {
        if(i%2 == 0)
        {
            for(int i2 = 0,x2 = n;i2<=n;i2++,x2--)
            {
                x[i2]=mn[i][x2];
            }
            for(int i2 = 0;i2<=n;i2++)
            {
                mn[i][i2]=x[i2];
            }
        }
    }
    for (int i1 = 0;i1 < m;i1++)
    {
        for (int i2 = 0;i2 < n;i2++)
        {
            if(mn[i1][i2] == aa)
            {
                cout << i1+1 << " " << i2+1;
            }
        }
    }
    return 0;
}
