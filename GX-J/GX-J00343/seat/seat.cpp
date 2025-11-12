#include <bits/stdc++.h>
using namespace std;
long long n,m,a[121],b[11][11],x=0,r=1,c=1,f=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    x=a[1];
    long long d=n*m;
    sort(a+1,a+d+1);
    for(int i=d;i>=1;i--)
    {
        b[r][c]=a[i];
        if(a[i]==x)
        {
            cout<<c<<" "<<r;
            break;
        }
        if(r==n && b[r-1][c]!=0)
        {
            c++;
            f=1;
        }
        else if(r==1 && c!=1 && b[r+1][c]!=0)
        {
            c++;
            f=0;
        }
        else if(f==0)
        {
            r++;
        }
        else if(f==1)
        {
            r--;
        }
    }
    return 0;
}
