#include <bits/stdc++.h>
using namespace std;
long long n,m,a[105],c,r,s,w;
bool px(long long x,long long y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >>n>>m;
    for(long long i=1;i<=n*m;i++)
        cin >>a[i];
    s=a[1];
    sort(a+1,a+1+n*m,px);
    for(long long i=1;i<=n*m;i++)
    {
        if(a[i]==s)
        {
            w=i;
            break;
        }
    }
    if(w%n==0)
        c=w/n;
    else
        c=w/n+1;
    if(c%2==1)
    {
        if(w%n==0)
            r=n;
        else
            r=w%n;
    }
    else
    {
        if(w%n==0)
            r=1;
        else
            r=n+1-w%n;
    }
    cout <<c<<" "<<r;
    return 0;
}
