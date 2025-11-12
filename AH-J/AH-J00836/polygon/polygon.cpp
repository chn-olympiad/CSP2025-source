#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
   int n,a[1005],s=0,max=0;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i];
      s+=a[i];
   }
   for(int i=1;i<=n;i++)
	   if(max<a[i])
	   max=a[i];
   if(n>=3&&s>(max*2))
   cout<<1;
   else
   cout<<0;
   return 0;
}

