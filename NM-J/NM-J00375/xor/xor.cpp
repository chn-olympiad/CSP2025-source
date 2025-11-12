#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[50003];
long long ans,cnt,cntt;
int main()
{
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
   cin>>n>>k;
   for(int i=1;i<=n;i++)
   {
    cin>>a[i];
	   for(int i=1;i<=n;i++)
	     {
	     	ans=a[i];
	     	cnt=0;
	     	for(int j=i+1;j<=n;j++)
	     	  {
	     	  	if(ans==k)
	     	  	cnt++;
			   }
			   if(i+1<=n)
			ans*=a[i+1];
		 }
		 cntt=(cnt,ans);
   }
  cout<<cntt;
fclose(stdin);
fclose(stdout);
return 0;
}
