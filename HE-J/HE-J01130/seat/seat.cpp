#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    long long xx[1001];
    cin>>n>>m;
    for (int i=0;i<n*m;i++)
    {
        int a;
        cin>>a;
        xx[i]=a;
    }
    int grt;
    grt=xx[0];
    int s;
    for (int j=0;j<n*m;j++)
    {
        for (int i=0;i<n*m;i++)
        {
            if (xx[i]<xx[i+1])
            {
                s=xx[i];
                xx[i]=xx[i+1];
                xx[i+1]=s;
            }
        }
    }
    int q=1;
    int d=0;
    int l=1;
    for (int i=0;i<=n*m;i++)
    {
        d+=1;
        if (xx[i]==grt)
        {
            cout<<l<<" ";
            if (q==1)
            {
                cout<<d;
            }
            else
            {
                cout<<n-d+1;
            }

        }
        if (d==n)
        {
            d=0;
            l+=1;
            if (q==1)
            {
                q=0;
            }
            else
            {
                q=1;
            }
        }
    }
    return 0;
}
