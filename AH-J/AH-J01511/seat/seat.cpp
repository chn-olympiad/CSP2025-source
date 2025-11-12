#include <bits/stdc++.h>
using namespace std;
int n,m,sum,num,a,x=1,y=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>num;
    for(int i=2;i<=n*m;i++)
        cin>>a,sum+=(a>num);
    while(sum--)
    {
        if(y%2)
            x++;
        else
            x--;
        if(x==0)
            y++,x=1;
        else if(x==n+1)
            y++,x=n;
    }
    cout<<y<<" "<<x;
    return 0;
}
