#include<bits/stdc++.h>
using namespace std;
long long cj[105];
int main()
{
    freopen("seat.in", "r",stdin);
    freopen("seat.out", "w",stdout);
    long long n,m;
    cin>>n>>m;
    for (long long i=1;i<=n*m;i++)
    {
        cin>>cj[i];
    }
    long long l=cj[1];
    sort(cj+1,cj+n*m+1);
    long long w=0,c=1;
    for (long long i=n*m;i>=1;i--)
    {
        if (cj[i]==l)
        {
            w=c;
            break;
        }
        c++;
    }
    if (w%n==0)
    {
        long long l1=w/n;
        cout<<l1<< " " ;
        if (l1%2==1)
        {
            cout<<n;
        }
        else
        {
            cout<<1;
        }
    }
    else
    {
        long long l1=w/n+1;
        cout<<l1<< " " ;
        if (l1%2==1)
        {
            cout<<w%n;
        }
        else
        {
            cout<<n-w%n+1;
        }
    }

    return 0;
}

