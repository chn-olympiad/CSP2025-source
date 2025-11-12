#include <bits/stdc++.h>
using namespace std;

int n,m,a,b,k=1,l,p,r;
int main ()
{
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    cin>>n>>m;
    l=n*m;
    cin>>a;
    for (int i=2;i<=l;i++)
    {
        cin>>b;
        if (b>a)
        {
            k++;
        }
    }
    p=k/n;
    r=k%n;
    if (r==0)
    {
        cout<<p<<" "<<m;
    }
    else if (p%2==1)
    {
        cout<<p+1<<" "<<m-r+1;
    }
    else
    {
        cout<<p+1<<" "<<r;
    }
    return 0;
}
