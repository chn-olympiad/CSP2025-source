#include<bits/stdc++.h>
using namespace std;
int m,n,b,a,num,c,r;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a;
    num=1;
    for(int i=2;i<=n*m;i++)
    {
        cin>>b;
        if(a<b)
        {
            num++;
        }
    }
    c=(num-1)/n+1;
    if(c%2==0)
    {
        r=n-num%n+1;
    }
    else
    {
        r=(num-1)%n+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
