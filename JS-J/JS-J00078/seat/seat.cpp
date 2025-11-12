#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000],s,x,y;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
   // freopen("seat.in","r",stdin);
   // freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    s=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==s)
        {
            s=i;
            break;
        }
    }
    x=(s+n-1)/n;
    s=s-(x-1)*n;;
    if(x%2==1)
    {
        y=s;
    }
    else
    {
        y=n-s+1;
    }
    cout<<x<<" "<<y;
    return 0;
}
