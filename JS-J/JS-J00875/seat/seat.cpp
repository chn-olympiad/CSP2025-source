#include<bits/stdc++.h>

using namespace std;
bool mycmp(int a,int b)
{
    return a>b;
}
int n,m;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int flag=a[1],p;
    sort(a+1,a+n*m,mycmp );
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==flag)
        {
            p=i;
        }
    }
    int c,r;
    if(p%n==0)
    {
        c=p/n;
        if(c%2==1)
        {
            r=n;
        }
        else
        {
            r=1;
        }
    }
    else
    {
        c=p/n+1;
        if(c%2==1)
        {
            r=p%n;
        }
        else
        {
            r=n-(p%n)+1;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
