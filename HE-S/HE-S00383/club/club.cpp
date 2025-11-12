#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int sum = 0;
        int n,a[100005],b[100005],c[100005];
        int max1 = 0,max2 = 0,max3 = 0;
        cin >> n;
        int fen = n/2;
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i] >> b[i] >> c[i];
            if (a[i] >= max(b[i],c[i]))
                max1++;
            else if(b[i] >= max(a[i],c[i]))
                max2++;
            else
                max3++;
        }
        bool qwerr = 1;
        if (max(max(max1,max2),max3) <= fen)
        {
            for (int i = 1;i <= n;i++)
                sum += max(max(a[i],b[i]),c[i]);
            cout << sum << endl;
            qwerr = 0;

        }
        if(!qwerr)
            qwerr = 1;
        else
        {
            if(max1 >= max(max2,max3))
            {
                for (int i = 1;i <= n;i++)
                {
                    if(max(b[i],c[i]) >= a[i])
                    {
                        sum += max(b[i],c[i]);
                        a[i] = 0;
                        b[i] = c[i] = -999999;
                    }
                }
                int summ = 0;
                for (int i = n;i >= 1;i--)
                {
                    if (a[i] != 0)
                        summ++;

                }
                summ = summ-(n/2);
                for (int i = 1;i <= summ;i++)
                {
                    long long summm = a[n]-max(b[n],c[n]);
                    int xia = 0;
                    for(int j = n;j >= 1;j--)
                    {

                        if(a[i] != 0)
                        {
                            if (summm >= a[i]-max(b[i],c[i]))
                            {
                                summm = a[i]-max(b[i],c[i]);
                                xia = i;
                            }
                        }

                    }
                    a[xia] = 0;
                    sum += max(b[i],c[i]);
                    b[i] = c[i] = -999999;
                }
                for (int i = 1;i <= n;i++)
                    if (a[i] != 0)
                        sum += a[i];
                cout << sum << endl;
            }
            else if(max2 >= max(max1,max3))
            {
                for (int i = 1;i <= n;i++)
                {
                    if(max(a[i],c[i]) >= b[i])
                    {
                        sum += max(a[i],c[i]);
                        b[i] = 0;
                        a[i] = c[i] = -999999;
                    }
                }
                int summ = 0;
                for (int i = n;i >= 1;i--)
                {
                    if (b[i] != 0)
                        summ++;

                }
                summ = summ-(n/2);
                for (int i = 1;i <= summ;i++)
                {
                    long long summm = b[n]-max(a[n],c[n]);
                    int xia = 0;
                    for(int j = n;j >= 1;j--)
                    {

                        if(b[i] != 0)
                        {
                            if (summm >= b[i]-max(a[i],c[i]))
                            {
                                summm = b[i]-max(a[i],c[i]);
                                xia = i;
                            }
                        }

                    }
                    b[xia] = 0;
                    sum += max(a[i],c[i]);
                    a[i] = c[i] = -999999;
                }
                for (int i = 1;i <= n;i++)
                    if (b[i] != 0)
                        sum += b[i];
                cout << sum << endl;
            }
            else if(max3 >= max(max1,max2))
            {
                for (int i = 1;i <= n;i++)
                {
                    if(max(a[i],b[i]) >= c[i])
                    {
                        sum += max(b[i],c[i]);
                        c[i] = 0;
                        a[i] = b[i] = -999999;
                    }
                }
                int summ = 0;
                for (int i = n;i >= 1;i--)
                {
                    if (c[i] != 0)
                        summ++;

                }
                summ = summ-(n/2);
                for (int i = 1;i <= summ;i++)
                {
                    long long summm = c[n]-max(a[n],b[n]);
                    int xia = 0;
                    for(int j = n;j >= 1;j--)
                    {

                        if(c[i] != 0)
                        {
                            if (summm >= c[i]-max(a[i],b[i]))
                            {
                                summm = c[i]-max(a[i],b[i]);
                                xia = i;
                            }
                        }

                    }
                    c[xia] = 0;
                    sum += max(a[i],b[i]);
                    a[i] = b[i] = -999999;
                }
                for (int i = 1;i <= n;i++)
                    if (b[i] != 0)
                        sum += c[i];
                cout << sum<< endl;
            }
        }
    }
    return 0;
}
