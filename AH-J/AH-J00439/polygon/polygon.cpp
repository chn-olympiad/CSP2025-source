#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],s[5005]={0};
int ans=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    if(n<3) cout<<0;
    if(n==3)
    {
		if(a[1]+a[2]+a[3]>2*a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
    for(int i=1;i<=n;i++)
    {
		s[i]=s[i-1]+a[i];
	}
	if(n==5||n==4)
	{
		for(int i=1;i<=n;i++)
		 for(int j=i+1;j<=n;j++)
		  for(int k=j+1;k<=n;k++)
		   {
			   if(a[i]+a[j]+a[k]>2*a[k]) ans=ans+1+(j-i-1)+(k-j-1)+i-1,ans%=998244353;
			   else break;
		   }
		   cout<<(ans+1)%998244353;
		   return 0;
	}
	if(n==6)
	{
		for(int i=1;i<=n;i++)
		 for(int j=i+1;j<=n;j++)
		  for(int k=j+1;k<=n;k++)
		   {
			   if(a[i]+a[j]+a[k]>2*a[k]) {ans=ans+1+(j-i-1)+(k-j-1)+i-1,ans%=998244353;
			   if(k==n) ans+=3;   }    
		   }
		   cout<<(ans+1)%998244353;
		   return 0;
	 }
	 if(n==7)
	{
		for(int i=1;i<=n;i++)
		 for(int j=i+1;j<=n;j++)
		  for(int k=j+1;k<=n;k++)
		   {
			   if(a[i]+a[j]+a[k]>2*a[k]){ ans=ans+1+(j-i-1)+(k-j-1)+i-1,ans%=998244353;
			   if(k==n-1) ans+=3; 
			   if(k==n) ans+=6;
			   ans%=998244353;  }    
		   }
		   cout<<(ans+1)%998244353;
		   return 0;
	 }
	  if(n==8)
	{
		for(int i=1;i<=n;i++)
		 for(int j=i+1;j<=n;j++)
		  for(int k=j+1;k<=n;k++)
		   {
			   if(a[i]+a[j]+a[k]>2*a[k]) {ans=ans+1+(j-i-1)+(k-j-1)+i-1,ans%=998244353;
			   if(k==n-2) ans+=3; 
			   if(k==n-1) ans+=6;
			   if(k==n) ans+=10;
			   ans%=998244353;    }    
		   }
		   cout<<(ans+1)%998244353;
		   return 0;
	 }
	  if(n==9)
	{
		for(int i=1;i<=n;i++)
		 for(int j=i+1;j<=n;j++)
		  for(int k=j+1;k<=n;k++)
		   {
			   if(a[i]+a[j]+a[k]>2*a[k]) {ans=ans+1+(j-i-1)+(k-j-1)+i-1,ans%=998244353;
			   if(k==n-3) ans+=3; 
			   if(k==n-2) ans+=6;
			   if(k==n-1) ans+=10;
			   if(k==n) ans+=15;
			   ans%=998244353;}    
		   }
		   cout<<(ans+1)%998244353;
		   return 0;
	 }
	 	  if(n==10)
	{
		for(int i=1;i<=n;i++)
		 for(int j=i+1;j<=n;j++)
		  for(int k=j+1;k<=n;k++)
		   {
			   if(a[i]+a[j]+a[k]>2*a[k])
			   { 
			   ans=ans+1+(j-i-1)+(k-j-1)+i-1,ans%=998244353;
			   if(k==n-4) ans+=3; 
			   if(k==n-3) ans+=6;
			   if(k==n-2) ans+=10;
			   if(k==n-1) ans+=15;
			   if(k==n) ans+=21;
			   ans%=998244353;      
			   }     
		   }
		   cout<<(ans+1)%998244353;
		   return 0;
	 }
    return 0;
}
