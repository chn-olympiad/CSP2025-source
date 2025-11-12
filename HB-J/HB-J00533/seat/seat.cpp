#include <iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a,b,d=0,c,r,z;
    cin>>n>>m>>a;
    z=n*m-1;
    for(int i=0;i<z;i++)
    {
        cin>>b;
        if(b>a)
        {
            d++;
        }
    }
    c=d/n+1;
    if(d/n%2==0)
    {
        r=d%n+1;
    }
    else if((d/n)%2==1)
    {
        r=n-d%n;
    }
    cout<<c<<" "<<r;
    return 0;
}
