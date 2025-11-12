#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a,y,s,sz[7],sy,h,y;
	sy=0;
	cin>>a;
	for(int i=1;i<=6,i++)
	{
		y=1;
		y*=10;
		if(a/y>0)
		{
			sy+=1;
			sz[i]=a%y;
			a=a/10;
		}
	}
	for(int k=1;k<=5;k++)
	{
	    for(int j=1;j<=sy;j++)
		{
		    if(sz[j]<sz[j+1])
			{
	    		h=sz[j+1];
				sz[j+1]=sz[j];
				sz[j]=h;
			}
		}
    }
    for(int i=1;i<=sy;i++)
    {
    	y=1;
    	y*=10;
    	
    	
	}
	a=0;
	for(int i=1;i<=sy;i++)
	{
		a+=sz[i]*y;
		y/=10;
		
	}
	cout<<a;
	return 0;
}
