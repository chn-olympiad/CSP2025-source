#include<bits/stdc++.h>
using namespace std;
int a[20],x,y,m=0,n,l=0,h=0,w=1;//m指未录人数 n指剩余可能人数 l已录用人数 h可行方法 
int main()
{

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>x>>y;
	int k;
	cin>>k;
	cin>>a[n];
	for(int t=0;t<=x;t++)
	{
		w=t*w;
	}
	for(int i=0;i<=x;i++)
	{
		if(m>=a[i])
		{
			n--;
			m++;
		}
		else
		    for(int u=0;u<=x;u++)
		    {
		    	if((k+1)%10==1)
		    	{
		    
					if(l<y)
					{
					   l++;
					   m++;
					   n--;
					} 
			    }
		    	else
		    	{
					if(l<y)
					{
				       m++;
			           n--;
					} 
			    }   
		    }
	    
		if(l!=y)
			w++;
	}		
	cout<<w;
    return 0;
}
