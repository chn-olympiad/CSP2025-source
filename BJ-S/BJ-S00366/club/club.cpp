#include<bits/stdc++.h>
using namespace std;


int ab[200005],bc[200005],ac[200005],d[200005];
long long anst[10];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
        int n;
        cin>>n;
        
		long long ans=0;
		
        int bb=n/2;
        
		int xa=0,ya=0,za=0;
		int x,y,z;
		
		memset(d,0,sizeof(d));
		memset(ab,0,sizeof(ab));
		memset(bc,0,sizeof(bc));
		memset(ac,0,sizeof(ac));
		
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y>>z;
            ab[i]=x-y;
            bc[i]=y-z;
            ac[i]=x-z;
            
  			if(x>=y&&x>=z)
			{
				ans+=x;
				xa++;
			}
			else if(y>=z)
			{
				ans+=y;
				ya++;
			}
			else
			{
				ans+=z;
				za++;
			}
        } 

        int dd=0;
        if(xa>bb)
		{
			for(int i=1;i<=n;i++)
			{
				if(ab[i]>0&&ac[i]>0){
					d[++dd]=min(ab[i],ac[i]);
				}
			}	
			sort(d+1,d+1+dd);
			for(int i=1;i<=xa-bb;i++)
			{
				ans-=d[i];
			}
		}
		else if(ya>bb)
		{
			for(int i=1;i<=n;i++)
			{
				if(bc[i]>0&&ab[i]<0)
				{
					d[++dd]=min(abs(ab[i]),bc[i]);
				}
				
			}	
			sort(d+1,d+1+dd);
			for(int i=1;i<=ya-bb;i++)
			{
				ans-=d[i];
			}
		}  
		else if(za>bb)
		{
			for(int i=1;i<=n;i++)
			{
				if(bc[i]<0&&ac[i]<0)
				{
					d[++dd]=min(abs(ac[i]),abs(bc[i]));
				}
			}
			sort(d+1,d+1+dd);
			for(int i=1;i<=za-bb;i++)
			{
				ans-=d[i];
			}
		} 
		
		anst[j]=ans;
		
    }
    for(int i=1;i<=t;i++)
    {
		cout<<anst[i]<<endl;
	}
    return 0;
}



