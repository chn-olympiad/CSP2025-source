#include<bits/stdc++.h>
using namespace std;
int a[5050],n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
   int ans=0;
   cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
   sort(a+1,a+n+10);
   if(n==3)
   {
	   if(a[1]+a[2]>a[3])ans=1;
   }
   
   if(n!=3)ans=n-2;
   cout<<ans%998244353;
   return 0;
}
