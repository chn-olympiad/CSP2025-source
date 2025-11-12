#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=1,y=1,ans=1;
	cin>>n>>m;
	int a[125]={0};
	int b[11][11]={0};
	for(int i=1;i<=n*m;i++)
	{
		
		cin>>a[i];
			
		
	}
	int xiaoR=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[j+1]>a[j])
			{
				swap(a[j+1],a[j]);
			}
			
		}
	}
	
	while(b[x][y]!=xiaoR)
	{
		b[x][y]=a[ans];
		if(b[x][y]==xiaoR)
		{
			
			cout<<y<<" "<<x;
			break;
		}
		if(y%2==1)
		{
			
			if(x==n)
			{
				y++;
			}
			else x++;		
		}
		 
		else if(y%2==0 )
		{
			if(x==1)
			{
				y++;
			}
			else x--;
		}
		ans++;
		
	}
	return 0;		
			
		
	
	
}