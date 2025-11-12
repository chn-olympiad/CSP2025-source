#include<bits/stdc++.h>
int main(){
	feopen("club.in","r",stdin);
	feopen("club.out","w",stdout);
	int t;
	int a1,a2,a3;
	std::cin>>t;
	int x2[t];
    for(int b=1;b<=t;b++)
	{
	int n;
	std::cin>>n;
	int a[3];
	int x=0;
	int bz=n/2;
		for(int j=1;j<=n;j++)
	{
		a[1]=0;
		a[2]=0;
		a[3]=0;
		std::cin>>a[1];
		std::cin>>a[2];
		std::cin>>a[3];
	
				if(a[1]<a[2])
			{
				if(a[2]<a[3])
				{
					x+=a[3];
					a3+=1;
				}
				else
				{
					x+=a[2];
					a2+=1;
				}
			}
			else
			{
				if(a[1]<a[3])
			{
					x+=a[3];
					a3+=1;
			}
				else
				{
					x+=a[1];
					a1+=1;
				}
			}
}
	if(a1>bz&&a2>bz&&a3>bz)
	{
		
		if(a1>bz)
		{
			x-a[1];
			if(a[2]>a[3])
			{
				x+=a[2];
			}
			else
			{
				x+=a[3];
			}
		}
		else 
		{
			if(a2>bz)
		{
			x-a[2];
			if(a[1]>a[3])
			{
				x+=a[1];
			}
			else
			{
				x+=a[3];
			}
		}
		if(a3>bz)
		{
			x-a[3];
			if(a[2]>a[1])
			{
				x+=a[2];
			}
			else
			{
				x+=a[1];
			}
		}
	}
}
	x2[b]=x;
	 }
	 
	 for(int c=1;c<=t;c++)
	 {
	 	std::cout<<x2[c]<<" ";
	  } 
	  fclose(stdin);
	  fclose(stdout);
 return 0;
}
