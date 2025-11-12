#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,t,p;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==t)
        {
            p=i;
        }
    }
    int sx,sy;
    if(p%n==0)
    {
        sy=p/n;
        if(sy%2==1)
        {
            sx=n;
        }
        else
        {
            sx=1;
        }
    }
    else
    {
        sy=p/n+1;
        if(sy%2==1)
        {

            sx=p%n;
        }
        else
        {
            sx=n-p%n+1;
        }
    }
    cout<<sy<<" "<<sx;
    return 0;
}
