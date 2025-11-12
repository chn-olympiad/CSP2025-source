 #include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		int a[20005][5]={}; 
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];	
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]<=a[i+1][j])
				{
					a[i][j]=a[i+1][j];
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(x<=n/2)
				{
					x+=a[i][j];
				}
				if(y<=n/2)
				{
					y+=a[i][j+1];
				}	
				if(z<=n/2)
				{
					z+=a[i][j+2];
				}		
			}
		}
		cout<<x+y+z<<endl;
	}	
	return 0;
}

