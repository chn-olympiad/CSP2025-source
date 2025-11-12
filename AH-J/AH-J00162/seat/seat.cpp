#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
   int m,n,a1,c=1,r=1,j=0;
   char a[1000]={};
   cin >>n>>m;
   for(int i=0;i<n*m;i++)
   {
      cin >>a[i];
   }
   a1=a[0];
   sort(a+0,a+m*n);
   while(a1!=a[j])
   {
      if(a[j]==a1)
      {
        cout <<c<<' '<<r;
        return 0;
      }
      else
      {
        j++;
        if(r<n)
        {
          r++;
        }
        else{
         c++;
        }
      }
   }
   return 0;
}
