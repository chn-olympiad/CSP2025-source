#include <bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int n,m;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int xx=a[1];
    sort(a+1,a+m*n+1);
    int f;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==xx)
        {
            f=n*m-i+1;
            continue;
        }
    }
    //cout<<f<<" ";
    int x,y;
    if(f%n==0)
    {
        if((f/n)%2==0)
        {
            x=1;
            y=f/n;
        }
        else
        {
            x=n;
            y=(f/n);
        }
    }
    else
    {
        if((f/n+1)%2==0)
        {
            x=n+1-(f%n);
            y=f/n+1;
        }
        else
        {
            x=f%n;
            y=f/n+1;
        }
    }
    cout<<y<<" "<<x;
    return 0;
}
