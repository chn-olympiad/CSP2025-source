#include <bits/stdc++.h>
using namespace std;
int n,a[5005],maxn,po,poz;
int ac(int x,int y)
{
    int z = 0;
    if (y > 1)
    {
        for (int i = 1;i <=x;i++)
        {
            z+=ac(i-1,y-1);
        }
    }
    if (y==1)
    {
        for(int i = 1;i <= x;i++)
        {
            z+=i;
        }
    }
    return z;
}
int Max(int x,int y,int z)
{
    x=max(x,y);
    return max(x,z);
}
bool ab(int x,int y)
{
    for (int i = y;i <= n-x+1;i++)
    {
        for(int j = i+1;j < n-x+2;j++)
        {
            for (int k = j+1;k <= n-x+3;k++)
            {
                if (a[i]+a[j]+a[k] >  Max(a[i],a[j],a[k])*2)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        maxn = max(maxn,a[i]);
    }
    if (maxn==1)
    {
        for (int i = 3;i <= n;i++)
        {
            po += ac(n-1,i-1);
        }
    }
    else
    {
        for (int i = 3;i <= n;i++)
        {
            for (int j = 1;j <= n;j++)
                if (ab(i,j)==1)
                {
                    po++;
                }
        }
    }
    cout << po;
    return 0;
}
