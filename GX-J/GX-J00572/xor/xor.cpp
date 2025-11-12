#include <iostream>
#include <cmath>
using namespace std;
int aaa(int a,int b)
{
    if (a == b)
        return a;
    int a1 = a,b1 = b,na =1,nb = 1,a2 = 0,b2 = 0,ma = 0,mb = 0;
    while (a1 != 0)
    {
        a2 += (a1 % 2) * na;
        a1 /= 2;
        na *= 10;
        ma++;
    }
    while (b1 != 0)
    {
        b2 += (b1 % 2) * nb;
        b1 /= 2;
        nb *= 10;
        mb++;
    }
    int h = 0,g = 1;
    if (ma > mb)
    {
        for (int x = 1;x <= mb;x++)
        {
            if (a2 % 10 != b2 % 10)
                h += g;
            a2 /= 10;
            b2 /= 10;
            g *= 10;
        }
        for (int x = mb + 1;x <= ma;x++)
        {
            if (a2 % 10 == 1)
                h += g;
            a2 /= 10;
            g *= 10;
        }
    }
    else if (ma < mb)
    {
        for (int x = 1;x <= ma;x++)
        {
            if (a2 % 10 != b2 % 10)
                h += g;
            a2 /= 10;
            b2 /= 10;
            g *= 10;
        }
        for (int x = ma + 1;x <= mb;x++)
        {
            if (b2 % 10 == 1)
                h += g;
            b2 /= 10;
            g *= 10;
        }
    }
    else
        for (int x = 1;x <= ma;x++)
        {
            if (a2 % 10 != b2 % 10)
                h += g;
            a2 /= 10;
            b2 /= 10;
            g *= 10;
        }
    int u = 0,v = 1;
    u += (h % 10) * 1;
    h /= 10;
    while (h != 0)
    {
        int w = 1;
        for (int x = 1;x <= v;x++)
            w *= 2;
        u += (h % 10) * w;
        h /= 10;
        v++;
    }
    return u;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    int a[n + 1],i[500005],j[500005],i1 = 1,j1 = 1,num = 0;
    for (int x = 1;x <= n;x++)
        cin >> a[x];
    for (int x = 1;x <= n;x++)
        for (int y = x;y <= n;y++)
        {
            int m = 0;
            for (int z = x;z <= y;z++)
                m = aaa(a[z],m);
            if (m == k)
            {
                i[i1] = x;
                j[j1] = y;
                num++;
            }
        }
    cout << num;
    return 0;
}
