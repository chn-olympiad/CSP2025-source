#include<bits/stdc++.h>
using namespace std;
int n,m,z,b,y,t,k,u,v,k1,u1,v1;
int main()
{
    freopan("club.in","r",stdin);
    freopan("club.out","w",stdout);
    cin>>t;
    cin>>n;
    for(int i=1;i<=t;i++)
    {
       for(int j=1;j<=n;j++)
       {
        cin>>z>>b>>y;
            if(z>=b&&z>=y)
            {
				k++;
			    k1+=z;	
		    }
		    
		    if(b>=z&&b>=y)
            {
				u++;
			    u1+=b;	
		    }
		    
		    if(y>=z&&y>=z)
            {
				v++;
			    v1+=y;	
		    }
		}
		cout<<k1+u1+v1<<endl;
		k=0;
		k1=0;
		u=0;
		u1=0;
		v=0;
		v1=0;
	}
	return 0;
}
