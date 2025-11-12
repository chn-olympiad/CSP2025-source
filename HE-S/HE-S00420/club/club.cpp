#include<bits/stdc++.h>
using namespace std;
int a[4];
int b[4];
int c[4];
int w[1000];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
   long long int t,n,ans=0,m,k=1,j,i,y=0,yy=0,yyy=0;
	cin>>t;
		for(i=1;i<=t;i++)
	{
		cin>>n;
		int u=n/2;
		for(j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>b[j]&&a[j]>c[j])
			{
				ans=ans+a[j];
				y=y+1;
			}else
			if(a[j]<b[j]||a[j]<b[j])
			{
				if(b[j]>c[j])
				{
					ans=ans+b[j];
					yy=yy+1;
				}else
				{
					ans=ans+c[j];
					yyy=yyy+1;
				}
			}else
			if(b[j]>a[j]&&b[j]>c[j])
			{
				ans=ans+b[j];
				yy=yy+1;
			}else
			if(b[j]<c[j]||b[j]<a[j])
			{
				if(a[j]>c[j])
				{
					ans=ans+a[j];
					y=y+1;
				}else
				{
					ans=ans+c[j];
					yyy=yyy+1;
				}
			}else
			if(c[j]>b[j]&&c[j]>a[j])
			{
				ans=ans+c[j];
				yyy=yyy+1;
			}else
			if(c[j]<a[j]||c[j]<b[j])
			{
				if(b[j]>a[j])
				{
					ans=ans+b[j];
					yy=yy+1;
				}else
				{
					ans=ans+a[j];
					y=y+1;
				}
			}
		if(y>n/2||yy>n/2||yyy>n/2)
		{
			if(y>n/2)
		  {
		 	  if(b[j]>c[j])
			 {
				ans=ans-a[j]+b[j];
				yy=yy+1;
			 }else
			 {
				ans=ans-a[j]+c[j];
				yyy=yyy+1;
			 }	
		  }else
		  if(yy>n/2)
		  {
		  	  if(a[j]>c[j])
			 {
				ans=ans-b[j]+a[j];
				y=y+1;
			 }else
			 {
				ans=ans-b[j]+c[j];
				yyy=yyy+1;
			}	
		  } else
		  if(yyy>n/2)
		  {
		  	if(a[j]>b[j])
		  	{
		  	  ans=ans-c[j]+a[j];
		  	  y=y+1;
			}
			else
			{
				ans=ans-c[j]+b[j];
				yy=yy+1;
			}
		  }
		}	
	    
		w[i]=w[i]+ans;
		ans=0;
		y=0;
		yy=0;
		yyy=0;
		}
		
		
	} 
	for(i=1;i<=n;i++)
	{
		cout<<w[i]<<endl;
	}

	return 0;
}

