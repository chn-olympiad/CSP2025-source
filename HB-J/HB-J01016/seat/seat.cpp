#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,a[11][11],ma[105],an,lie,hang,ad;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
    {
        cin >> ma[i];
        if(i==1) an = ma[i];
    }
    sort(ma+1,ma+n*m+1);
    for(int i=n*m;i>=1;i--)
    {
        ad++;
        if(ma[i] == an)
        {
            an = ad;
            break;
        }
    }
    if(an>n)
    {
        if(an%n==0)
        {
            int t = an/n;
            if(t%2==0)
            {
                cout << t << " " << 1;
                return 0;
            }
            if(t%2==1)
            {
                cout << t << " " << n;
                return 0;
            }
        }
        else
        {
            int t2 = an/n+1;
            int t3 = an/n;
            int t4 = an - t3 * n;
            if(t2%2==0)
            {
                cout << t2 << " " << n-t4+1;
                return 0;
            }
            if(t2%2==1)
            {
                cout << t2 << " " << t4;
                return 0;
            }
        }

    }
    if(an<=n)
    {
        cout << 1 << " " << an;
        return 0;
    }
    return 0;
}
