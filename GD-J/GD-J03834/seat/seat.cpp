#include<bits/stdc++.h>
using namespace std;
int a[150]={};
int b[15][15];
int m=1,n=0;
int k=0,num=1;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;//n––m¡– 
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
		
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				b[j][i]=a[num];
				
				if(a[num]==k)
				{
					cout<<i<<" "<<j;
					return 0;
				} 
				num++;
			}
				
		} 
		else
		{
			for(int j=n;j>=1;j--)
			{
				b[j][i]=a[num];
				 
				if(a[num]==k)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				num++;
			}
		}
	
	
			
		
	}

	return 0;
 } 
