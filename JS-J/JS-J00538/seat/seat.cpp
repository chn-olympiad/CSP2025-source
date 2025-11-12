#include <bits/stdc++.h>
using namespace std;
int main()
{
   freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
     int a[n*m];
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int b=a[1],d;
    int e[n*m];
    sort(a+1,a+n*m+1,greater <int>());
    for(int i=1;i<=n*m;i++)
        e[i]=a[i];
    for(int i=1;i<=n*m;i++)
    {
        if(e[i]==b)
        {
            d=i;
            break;
        }
    }
    int c,r,mark;
    if(d%n==0)
    {
        c=d/n;
        if(d/n%2==0)
            r=1;
        else r=n;
    }

    else
    {
        c=d/n+1;
        for(int i=0;i<m;i++)

    {
        if(i*n<=d&&(i+1)*n>=d)
            {
                mark=i+1;
                break;
            }
    }
    if(mark%2==0)
    {
       if(abs(mark*n-d)<n)
      r=1+abs(mark*n-d);
    }
    else
    r=n-abs(mark*n-d);
    }
    cout<<c<<" "<<r<<endl;
   return 0;
}

