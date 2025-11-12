#include<iostream>
using namespace std;
int comp,n=0,m,s,sp=1,gc1,gc2,x,y;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=2; i<=n*m; i++)
    {
       cin>>comp;
       if(comp>s)
        sp++;
    }
    gc1=sp%(2*n);
    gc2=(sp-gc1)/(n);
    if(gc1>n)
    {
        y=2*n-gc1+1;
        x=gc2+2;
    }
    else
    {
        y=gc1;
        x=gc2+1;
    }
    cout<<x<<" "<<y;
    return 0;
}
