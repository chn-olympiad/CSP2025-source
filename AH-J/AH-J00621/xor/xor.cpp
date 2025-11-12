#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],c;
int main()
{
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>n>>k;
   for(int i=1;i<=n;i++)
   {
	   cin>>a[i];
	   if(a[i]==1)c++;
	   a[i]=a[i-1]^a[i];
   }
   if(c==n&&k==0)
   {
	   cout<<n/2;
	   return 0;
   }
   c=0;
   for(int l=1,r=1;l<=n&&r<=n;r++)
   {
	   if(a[l-1]^a[r]==k)
	   {
		   c++;
		   l=r+1;
	   }
   }
   cout<<c;
   return 0;
}
