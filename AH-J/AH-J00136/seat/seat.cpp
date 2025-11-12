#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[110];
long long cnt;
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n*m;i++)
   {
       cin>>a[i];
   }
   cnt=a[1];
   sort(a+1,a+n*m+1,cmp);
   for(int i=1;i<=n*m;i++)
   {
       if(a[i]==cnt)
       {
          cnt=i;
          break;
       }
   }
   long long f1=cnt%n;
   long long f2=cnt/n;
   if(f1==0)
   {
	   cout<<f2<<" "<<n;
	   return 0;
   }
   f2++;
   if(f2%2==0)
   {
      cout<<f2<<" "<<n-f1+1;
   }
   else if(f2%2!=0)
   {
      cout<<f2<<" "<<f1;
   }
   return 0;
}
