#include<bits/stdc++.h>
using namespace std;
int n,m,R,num;
int t[105],step[15][15],a[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>t[i];
	}
	R=t[1];
	sort(t+1,t+n*m+1,greater<int>());
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)	
		{						
			num++;				
			step[i][j]=t[num];		 
		}						 
	}						 
	for(int i=1;i<=m;i++)		 
	{							 
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				a[j][i]=step[i][j];
			}
		}
		else				 
		{		
			int f=0;				 
			for(int j=n;j>=1;j--)
			{
				f++;
				a[f][i]=step[i][j];
			}
		}
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==R)
			{
				cout<<j<<" "<<i;
				exit(0);
			}
		}
	}
}
