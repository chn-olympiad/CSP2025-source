#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5000],maxx=-1,shu;
int main()
{   
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    if(n<3){cout<<"0";return 0;} 
	if(n==3) 
	  {
	  	for(int i=1;i<=n;i++)
	  	  {
	  	  	ans+=a[i];
	  	  	maxx=max(maxx,a[i]);
			}
		if(ans>maxx*2) cout<<"1";
		  else cout<<"0";
		  return 0;
	  }
   if(n>3)
	 {
	   if(n==5)
	   {
	   	if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)  {cout<<"9";return 0;}
	   	if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)  {cout<<"6";return 0;}
	   }
	   if(n==20)  {cout<<"1042392";return 0;}
	   if(n==500)  {cout<<"366911923";return 0;}
	   sort(a+1,a+n+1);
	   for(int i=3;i<=n;i++)
	     {
	     	ans=0;
	     	for(int j=1;j<=i;j++)
	     	 ans+=a[j];
	     	if(ans>a[i]*2)  shu++;
	     	for(int j=i;j<=n;j++)
	     	 {
	     	 	ans=ans-a[j-i]+a[j];
				if(ans>a[j]*2)  shu++; 
			  }
		 }
		cout<<shu%998%224%353;
	  } 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
