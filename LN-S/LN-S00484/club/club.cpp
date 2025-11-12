#include <bits/stdc++.h>
using namespace std;
int n[10001],p1 = 0, p2 = 0, p3 = 0, t, ans = 0, maxn = 0, midn = 0, minn = 2e4+1;
int a[50001],b[50001],c[50001],d[50001],num, an = 0;
int maxd(int a,int b,int c)
{
    if(a > b && a > c)
    {
        return a;
    }
    if(b > a && b > c)
    {
        return b;
    }
    if(c > a && c > b)
    {
        return c;
    }
}
string maxdn(int a,int b,int c)
{
    if(a > b && a > c)
    {
        return "a";
    }
    if(b > a && b > c)
    {
        return "b";
    }
    if(c > a && c > b)
    {
        return "c";
    }
}
int midd(int a,int b,int c)
{
    if(a > min(b,c) && a < max(b,c))
    {
        return a;
    }
    if(b > min(a,c) && b < max(a,c))
    {
        return b;
    }
    if(c > min(a,b) && c < max(a,b))
    {
        return c;
    }
}
int main()
{
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n[i];
        for (int j = 1; j <= n[i]; j++)
        {
            cin >> a[j] >> b[j] >> c[j];

            if(a[j] == maxd(a[j],b[j],c[j])) p1++;
            if(b[j] == maxd(a[j],b[j],c[j])) p2++;
            if(c[j] == maxd(a[j],b[j],c[j])) p3++;
            ans = ans + maxd(a[j],b[j],c[j]);
        }
        if(maxd(p1,p2,p3) <= n[i]/2)
            cout << ans << endl;
        if(p2 == 0 && p3 == 0)
        {
            num = n[i]/2;
            for(int z = 1; z <= num; z++){
            for(int j = 1; j <= n[i]; j++)
            {
                if(a[j] > maxn)
                {
                    maxn = a[j];
                }
            }
            for(int j = 1; j <= n[i]; j++)
            {
                if(a[j] == maxn)
                    a[j] == 0;
            }

            an = an + maxn;
            maxn = 0;
            }
        }
        cout << an << endl;
        if(maxd(p1,p2,p3) > n[i]/2)
        {
            int num1, maxn1;
            maxn1 = maxd(p1,p2,p3);
            num1 = maxd(p1,p2,p3) - n[i]/2;

        }

    }
    return 0;
}
