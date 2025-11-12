#include<bits/stdc++.h>
using namespace std;
bool cmi(int x,int y)
{
	return x>y;
}
int  main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;	
		int c[3][n],cc[3][n];
		for(int j=0;j<n;j++)
		{
			cin>>c[0][j]>>c[1][j]>>c[2][j];
			cc[0][j]=c[0][j]; 
			cc[1][j]=c[1][j]; 
			cc[2][j]=c[2][j]; 
		}
		sort(cc[0],cc[0]+n,cmi);
		sort(cc[1],cc[1]+n,cmi);
		sort(cc[2],cc[2]+n,cmi);
		for(int j=0;j>n;j++) 
		{
			int sum;
			if(cc[0][j]>cc[1][j]&&cc[0][j]>cc[2][j])
			{
				
			}
			else()
		}
	}	
	return 0;
} 
