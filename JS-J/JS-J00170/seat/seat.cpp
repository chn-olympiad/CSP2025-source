#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,num=0,c,r;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
       cin>>a[i];
       x=a[1];
    }
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==x)
        {
            num=n*m-i+1;
        }
    }
    if(num%n==0)
    {
        cout<<num/n<<" "<<m;
    }
    else
    {
        c=num/n+1;
         if(num%(2*n)>n)
        {
            r=2*n-num%(2*n)+1;
        }
        else
        {
            r=num%(2*n);
        }
        cout<<c<<' '<<r;
    }
    return 0;
}
