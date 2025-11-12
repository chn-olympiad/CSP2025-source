#include<bits/stdc++.h>
using namespace std;
int n,t,sum;
int main()
{
	freopen("problem","r",stdin);
	freopen("problem","w",stdout);	
	cin>>n,t;
	int a[n][t];
	for(int y=1;y<=3;y++){
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=t;j++)
			{
				cin>>a[i][j];
			}	
		}	
	}
	for(int e=1;e<=a[t][n];e++)    
	{
		if(e%2==0)	
		{
			sum+=e;	
		}	
		sum+=a[n][t];	
	}	
	cout<<sum;																							}                                                                                            
	fclose(stdin);
	fclose(stdout);
	return 0;	
}