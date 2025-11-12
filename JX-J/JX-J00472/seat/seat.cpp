#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,sb=0,n=0;
    cin>>a>>b;
    int c[a][b],d[a*b];
    for (int i=1;i<=a*b;i++)
    {
        cin>>d[i];

    }
    sb=d[1];
    for (int j=1;j<=101;j++)
    {
        for (int i=2;i<=a*b-1;i++)
        {
            if (d[i]>d[i-1]){
                swap(d[i],d[i-1]);
            }
        }
    }

    for (int i=1;i<=a*b;i++)
    {
        if (d[i]==sb)
        {
            n=i;
        }
    }
    int lie=n/a,hang=n%a;
    if (lie==0)
    {
        cout<<1<<n;
    }
    if  ((lie+1)%2!=0)
    {
        if (hang==0)
        {
            cout<<lie<<" "<<a;
        }
        else{
            cout<<lie+1<<" " <<hang;
        }
    }
    else if ((lie+1)%2==0)
    {
        if (hang==0)
        {
            cout<<lie+1<<" "<<a;
        }
        else
        {
            cout<<lie+1<<" "<<a-hang+1;
        }
    }

    return 0;
}
