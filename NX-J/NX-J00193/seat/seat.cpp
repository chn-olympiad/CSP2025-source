#include <bits/stdc++.h>
using namespace std;

int a[101];

bool sort_state(int i1, int i2)
{
    return i1>i2;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b=0;;
    cin >>n>>m;
    for(int i=1; i<=n*m; i++)
    {
        cin >>a[i];
    }
    b = a[1];
    sort(a+1, a+n*m+1, sort_state);
    int l=0,r=n*m;
    while(a[l]!=b)
    {
        if(a[(r-l)/2+l]<b)
        {
            r -= (r-l)/2;
        }
        if(a[(r-l)/2+l]>=b)
        {
            l += (r-l)/2;
        }
    }
    cout <<(l-1)/n+1<<" ";
    if(((l-1)/n+1)%2!=0)
    {
        if(l%n)
        {
            cout <<l%n;
        }
        else
        {
            cout <<n;
        }
    }
    else
    {
        if(l%n)
        {
            cout <<n-l%n+1;
        }
        else
        {
            cout <<1;
        }
    }
    return 0;
}
