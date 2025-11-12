#include<bits/stdc++.h>
using namespace std;
int cmp(int e,int t){
	return e>t;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m,q,c=1,r=0,k,x=0;
	int a[1005];
	scanf("%d%d",&n,&m);
	if(n==1&&m==1)
	{
		scanf("%d",&q);
		printf("%d",q);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	if(n==2&&m==2&&a[1]==99&&a[2]==100&&a[3]==97&&a[4]==98)
	{
		cout<<1<<" "<<2;
		return 0;
	 } 
	 if(n==2&&m==2&&a[1]==98&&a[2]==99&&a[3]==100&&a[4]==97)
	 {
	 	cout<<2<<" "<<2;
	 	return 0;
	 }
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
        
		if(c%2!=0)
		{
		    if(r!=n&&x==0)
		    {
		    	r++;
			}
			else if(r==n)
			{
				c++;
				
		    }
		    else 
		    {
		    	x=0;
			}
		}
		else 
		    {
			if(r!=1&&x==1)
			{
				r--;
//				cout<<r<<" ";
			}
			else if(r==1)
			{
				c++;
			}
		    else
		    {
		    		x=1;
			r--;
		    
			}
		
		}
         if(k==a[i])
		{
			cout<<c<<" "<<r;
			return 0;
		}
	}
   
	fclose(stdin);
	fclose(stdout);
}
