#include<bits/stdc++.h>
using namespace std;
int m,n,s[105];
int main()
{
    freopen(seat.in,"r",stdin);
    freopen(seat.out,"w",stdout);
    int cnt=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&s[i]);
    }
    for(int i=2;i<=n*m;i++)
    {
        if(s[i]>s[1]) cnt++;
    }
    int c,r;
    if(cnt<=n)
    {
        cout<<1<<" "<<cnt;
        return 0;
    }
    if(cnt%n!=0)
    {
        c=cnt/n+1;
        if(c%2==1)
        {
            r=cnt%n;
        }
        else
        {
            r=n+1-cnt%n;
        }
    }
    else
    {
        c=cnt/n;
        if(c%2==1)
        {
            r=n;
        }
        else
        {
            r=1;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
