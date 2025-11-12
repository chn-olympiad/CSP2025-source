#include<bits/stdc++.h>
using namespace std;
int a[500010];
long long x[500010],ans;
int n,k;
int main()
{
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   cin>>n>>k;
   if(k<=1)
   {
	   for(int i=1;i<=n;i++) cin>>a[i];
	   if(k==1)
	   {
		   for(int i=1;i<=n;i++)
		   {
			   if(a[i]==1) ans++;
		   }
	   }
	   else if(k==0)
	   {
		   for(int i=1;i<=n;i++)
		   {
			   if(a[i]==0) ans++;
		   }
		   for(int i=1;i<=n;i++)
		   {
			   if(a[i]==1&&a[i+1]==1)
			   {
				   ans++;
				   i++;
			   }
		   }
	   }
   }
   else
   {
	   for(int i=1;i<=n;i++) 
	   {
		   cin>>a[i];
		   x[i]=x[i-1]^a[i];
	   }
	   int l=1,r=1;
	   while(r<=n)
	   {
		   if((x[r]^x[l-1])==k)
		   {
			   ans++;
			   l=r+1;
		   }
		   r++;
	   }
   }
   
   cout<<ans;
   return 0;
}
//2 3 3 0
