#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}
int n,m,a[105],x,l,c,r;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    int c=1,r=0;
    for(int i=1;i<=n*m;i++)
    {
        if(c%2)
        {
            r++;
            if(r==n+1)
            {
                c++;
                r--;
            }
        }
        else
        {
            r--;
            if(r==0)
            {
                c++;
                r++;
            }
        }
        if(x==a[i])
            break;
    }
    cout<<c<<' '<<r;

    return 0;
}
