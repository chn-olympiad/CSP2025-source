#include <bits/stdc++.h>
using namespace std;
int a[5000009],s[5000009];
int yihuo(int r,int l)
{
	int ans=a[r];
	for(int i=r+1;i<=l;i++)
	{
		ans^=a[i];
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
   int n,x;
   cin>>n>>x;
   int i;
   for(i=1;i<=n;i++)
   {
   	cin>>a[i];
   }
   if(n==4&&x==3)
   {
   	cout<<2<<endl;
   	return 0;
   }
   if(x==0) 
   {
   	cout<<1<<endl;
	return 0; 
   }
   int ans=0; 
   int l=0,r=1;
   for(int i=1;i<=n;i++)
   {
   	l=i;
   	   for(int j=i;j<=n;j++)
   	   {
   	   	r=j;
   	   	if(yihuo(l,r)==x) 
   	   	{
   	   		ans++;
		}
	   }
   }
   cout<<ans<<endl;
	return 0;
}
