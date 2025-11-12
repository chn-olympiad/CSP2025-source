#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a,ai,num=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>ai;
            if(i==1&&j==1)
            {
                a=ai;
            }
            if(ai>a)
            {
                num++;
            }
        }
    }
    num++;
    int c,r;
    c=num/n;
    r=num%n;
    if(r!=0)
    {
        c++;
    }
    else
    {
        r=n;
    }
    if(c%2==0)
    {
        r=n-r+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
