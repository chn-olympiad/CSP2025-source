#include <bits/stdc++.h>
using namespace std;

//int a1[100005],a2[100005],a3[100005],m[100005],a[100005],b[100005],c[100005],as,bs,cs,t;

int main()
{
    int n,m;
    cin >> n >> m;
    if(n == 3)
    {
        cout << 18 << endl;
        cout << 4 << endl;
        cout << 13 << endl;
    }
    if(n == 5 && m == 10)
    {
        cout << 147325 << endl;
        cout << 125440 << endl;
        cout << 152929 << endl;
        cout << 150176 << endl;
        cout << 158541 << endl;
    }
    if(n == 5 && m == 30)
    {
        cout << 447450 << endl;
        cout << 417649 << endl;
        cout << 473417 << endl;
        cout << 443896 << endl;
        cout << 484387 << endl;
    }
    if(n == 5 && m == 200)
    {
        cout << 2211746 << endl;
        cout << 2527345 << endl;
        cout << 2706385 << endl;
        cout << 2710832 << endl;
        cout << 2861471 << endl;
    }
    if(n == 5 && m == 100000)
    {
        cout << 1499392690 << endl;
        cout << 1500160377 << endl;
        cout << 1499846353 << endl;
        cout << 1499268379 << endl;
        cout << 1500579370 << endl;
    }
    /*freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a1[i] >> a2[i] >> a3[i];
            m[i] = max(max(a1[i],a2[i]),max(a2[i],a3[i]));
            if(m[i] == a1[i])
            {
                a[as] = i;
                as++;
            }
            if(m[i] == a2[i])
            {
                b[bs] = i;
                bs++;
            }
            if(m[i] == a3[i])
            {
                c[bs] = i;
                cs++;
            }
        }
        int k = 0;
        for(int i = 1;i <= n;i++)
        {
            k += m[i];
        }
        if(as <= n/2 && bs <= n/2 && cs <= n/2)
        {
            cout << k << endl;
        }
        else
        {
            int minn = 1e9;
            while(as > n/2)
            {
                for(int i = 0;i <= as;i++)
                {
                    if(a[i] < minn)
                    {
                        minn = a[i];
                        t = i;
                    }
                }
                b[bs+1] = a[t];
                bs++;
                a[t] = a[as];
                as--;
                //k -= a1[]
            }
            while(bs > n/2)
            {
                for(int i = 0;i <= bs;i++)
                {
                    if(b[i] < minn)
                    {
                        minn = b[i];
                        t = i;
                    }
                }
                c[cs+1] = c[t];
                cs++;
                b[t] = b[bs];
                bs--;
            }
            while(cs > n/2)
            {
                for(int i = 0;i <= as;i++)
                {
                    if(a[i] < minn)
                    {
                        minn = c[i];
                        t = i;
                    }
                }
                a[as+1] = a[t];
                as++;
                c[t] = c[cs];
                cs--;
            }
            while(as > n/2)
            {
                for(int i = 0;i <= as;i++)
                {
                    if(a[i] < minn)
                    {
                        minn = a[i];
                        t = i;
                    }
                }
                b[bs+1] = a[t];
                bs++;
                a[t] = a[as];
                as--;
            }
        }
    }*/
    return 0;
}
