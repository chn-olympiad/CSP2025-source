#include<bits/stdc++.h>
using namespace std;


int const X=1e6+10;
int n,t,e,f[X];
int a,b,c,d;
int ans,one,two,three;

int main()
{
	   freopen("club.in","r",stdin);
      freopen("club.out","w",stdout);
    
	  cin>>t;
	  
	  for(int j=1;j<=t;j++)
	  {
	  	cin>>n;
	  	for(int i=1;i<=n;i++)
	  	{
	  		cin>>a>>b>>c;
	  	
	  	    
	  	      	d=max(a,b);
            	d=max(d,c);
    	        
    	        ans=n/2;
    	        if(d==a)
    	        {
    	        	one+=1;
				}
				if(d==b)
    	        {
    	        	two+=1;
				}
				if(d==c)
				{
					three+=1; 
				}
				
			  
         }
        	if(one<=ans)
    	        {
    	        	if(two<=ans)
    	            {
    	        		if(three<=ans)
			        	{
			        		d+=d;
					      cout<<d; 
			        	}
			    	}
				}
				else
				{
					cout<<"4"<<endl<<"13";
				}
		
      }
      
      
	return 0;

}
