#include <bits/stdc++.h>
using namespace std;
const int mx=110;
int  n,m,b[mx],c,y=1,t,z;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n*m; i++) b[i]=0;
    for (int i=1; i<=n*m; i++)
    {
        cin>>b[i];
        if(i==1)
        {
            c=b[i];
            b[0]=b[i];
        }
        if(b[i]>b[i-1])
        {
            int q=b[i];
            b[i]=b[i-1];
            b[i-1]=q;
        }
    }
    for (int i=1; i<=n*m; i++)
    {
        if(b[i]==c)
        {
            t=i;
            break;

        }
    }
    while(t>0)
    {
        if(t>n)
        {
            t-=n;
            y++;
        }
        else if(t<0)
        {
            z=t+n;
            break;
        }
        else
        {
            z=t;
            break;
        }
    }
    cout<<y<<" "<<z;
    return 0;
}
