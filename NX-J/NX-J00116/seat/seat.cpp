#include<bits/stdc++.h>;
using namespace std;


int main()
{




 int n,m,a[110],r=0,c=1;
   cin>>n>>m;
   for(int i=1;i<=n*m;i++)
   {
       cin>>a[i];
   }
    for(int i=2;i<=n*m;i++)
    {
        if(a[i]>a[1])
        {
            r++;
        }
    }
    r++;
    while(r>n)
    {
      r=r-n;
      c++;
    }

   if(c%2==0)
    {
       r=n-r+1;
    } freopen("seat.in","r",stdin);
    cout<<c<<"  ";
    cout<<r;
    freopen("seat.out","r",stdout);










    return 0;
}
