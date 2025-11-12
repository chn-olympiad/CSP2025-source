#include <bits/stdc++.h>
using namespace std;
int n,m,x,flag,t,g,minn=99999999999,f;
int s[1100005],c[1000005],d;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    x=n*m;
    for(int i=1;i<=x;i++)
    {
        cin>>s[i];
    }
    int r=s[1];
    for(int i=1;i<=x;i++)
    {
        if(s[i]<=s[i-1])
        {
            t=0;
            t=s[i-1];
            s[i-1]=s[i];
            s[i]=t;
        }
    }
    for(int i=1;i<=x;i++)
    {
        if(s[i]=r);
        {
            g=i;
        }
    }
    g--;
    for(int i=0;i<=1005;i++)
    {
        if(g-m*i<0)
        {
            d=i;
            break;
        }
    }
    int nx=g-(m*(d-1));
    int mx=d;
    cout<<mx<<" "<<nx-1;
    return 0;
}
