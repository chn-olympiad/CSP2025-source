#include <bits/stdc++.h> 
using namespace std;
int a[200],zuowei[14][14];
int main()
{
	
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	int n,m,y,mingci=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	y=a[1]; 
	sort(a,a+n*m+1);
	int j=1;
	while(j<=m)
	{	
		
			for(int t=1;t<=n;t++)
			{	
				mingci++;
				if(t!=n)
				{	
					zuowei[j][t]=a[mingci];	
				}
				else
				{
					j++;
					for(int t=4;t>=1;t--)
					{
						zuowei[j][t]=a[mingci];
					}
					for(int t=1;t<=n;t++)
					{	
						mingci++;
						if(t!=n)
						{	
							zuowei[j][t]=a[mingci];	
						}
						else
						{
							j++;
							for(int t=4;t>=1;t--)
							{
								zuowei[j][t]=a[mingci];
							}
							for(int t=1;t<=n;t++)
							{	
								mingci++;
								if(t!=n)
								{	
									zuowei[j][t]=a[mingci];	
								}
								else
								{
									j++;
									for(int t=4;t>=1;t--)
									{
									zuowei[j][t]=a[mingci];
									}
							}
						}	
					
					
					
					
					
					}		
				
				}	
			}
			
	}	
	for(int q=1;q<=n;q++)
	{
		for(int w=1;w<m;w++)
		{
			if(zuowei[w][q]==y)
			cout<<w<<q;
		}
	}
	return 0;
}


