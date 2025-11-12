#include<bits/stdc++.h>
using namespace std;
int m[10005],n,xz[10005],maxt=-1,sua=0,sums=0,ss=0,z=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i];
	}
	for(int v=1;v<=2;v++)
	{
		
		for(int o=1;o<=2;o++)
		{
			for(int p=1;p<=2;p++)
  	        {
	    	    for(int a=1;a<=2;a++)
		        {
		        	for(int s=1;s<=2;s++)
	                {
	                	for(int d=1;d<=2;d++)
	                	{
	                		for(int f=1;f<=2;f++)
                           	{
                           		for(int g=1;g<=2;g++)
                        		{
                        			for(int h=1;h<=2;h++)
                             		{
                             			for(int j=1;j<=2;j++)
                             			{
                             				if(v==1)
                             				{
                             					xz[1]=1;
											}
											if(o==1)
                             				{
                             					xz[2]=1;
											}
											if(p==1)
                             				{
                             					xz[3]=1;
											}
											if(a==1)
                             				{
                             					xz[4]=1;
											}
											if(s==1)
                             				{
                             					xz[5]=1;
											}
											if(d==1)
                             				{
                             					xz[6]=1;
											}
											if(f==1)
                             				{
                             					xz[7]=1;
											}
											if(g==1)
                             				{
                             					xz[8]=1;
											}
											if(h==1)
                             				{
                             					xz[9]=1;
											}
											if(j==1)
                             				{
                             					xz[10]=1;
											}
											for(int i=n+1;i<=10;i++)
											{
												if(xz[i]==1)
												{
													z=1;
												}
											}
											for(int i=1;i<=n;i++)
											{
												if(xz[i]==1)
												{
													sua=sua+m[i];
													maxt=max(maxt,m[i]);
													ss++;
												}
												if(maxt*2<sua&&ss>=3)
												{
													if(z==0)
													{
															sums++;
													}
												}
											}
											for(int i=1;i<=n;i++)
											{
												xz[i]=0;
											}
											sua=0;
											maxt=-1;
											ss=0;
											z=0;
										}
                              		}
                         		}
                        	}
                   		}
                	}
	        	}
	        }
		}
	}
	cout<<sums;
	return 0;
}
