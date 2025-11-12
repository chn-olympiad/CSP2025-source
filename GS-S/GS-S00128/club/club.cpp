#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,g=0,o=0,k,z=0;
int p=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin >> t;
	for(int h=1;h<=t;h++){
		cin>>n;
		p=0;
		g=0;
		z=0;
		o=0;
		for(int q=1;q<=n;q++){
			cin>>a>>b>>c;
			int s1 = max(a,b);
			int s2 = max(b,c);
			int s3 = max(s1,s2);

			if (s3==a)
			{
				if (g!=n/2){
					s3=a;
					g=g+1;
					
				}
				else{
					if (z!=n/2){
						s3=b;
					    z=z+1;
					}
					else{
						s3=c;
						o=o+1;
					}
				}
				
	     	}
			else {
				if (s3==b)
				{
					if (z!=n/2)
					{
					s3=b;
					z=z+1;
				    }
				    else{				    	
						if (g!=n/2){
							s3=a;
						    g=g+1;
						}
						else{
							s3=c;
							o=o+1;
						}
				}
				}
				else{
					if (s3==c)
					{
						if (o!=n/2)
						{
					        s3=c;
				        	o=o+1;
				        }
				        else{				    	
							if (g!=n/2){
								s3=a;
							    g=g+1;
							}
							else{
								s3=b;
								z=z+1;
							}
					}
				}
			
				
			}
			}




			
			p=p+s3;
			s1=0;
			s2=0;
			s3=0;						
	    
	    
	
	
	}
	cout<<p;
}
	
	return 0;

}
