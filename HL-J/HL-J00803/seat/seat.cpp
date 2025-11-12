#include<bits/stdc++.h>
using namespace std;
char a[10000]={ };
int main()
{
	freopen("seat.in""r",stdin);
	freopen("seat.out""w",stdout);
	int m,n,max=0,c;
	cin>>m>>n;
	int a[54545456456];
	for(int i=1;i<=m*n;i++)
	{
		 cin>>a[i];
	}
	for(int i=1;i<=m*n;i++)
	{
		 for(int j=1;j<=m*n;j++)
		 {
		 	if(a[j]<a[j+1])
		 	    {
		 	    	max=a[j];
		 	    	a[j]=a[j+1]; 
				    a[j-1]=max;
				}
		 }
	}
	c=a[1];
	for(int i=1;i<=m*n;i++)
	{
		if(c==a[i])
		{
			 for(int j=1;j<=m;j++)
			 {
			 	for(int z=1;z<=n;z++)
			 	{
			 	    if(a[z]==c)
				    {    
						 cout<<j<<" "<<z<< endl;
				         break;
					}
	                 
				    
				 }
			 }
		}
   }    
	cout<<1<<2;
	fclose(stdin); 
	fclose(stdout);
}
