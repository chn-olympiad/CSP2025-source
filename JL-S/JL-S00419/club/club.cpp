#include<bits/stdc++.h>
using namespace std;
int a[6][6][10000],n[6];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int t,c=0;
	cin>>t;
	int max=0;
	for(int i=0;i<t;i++)
	{
		cin>>n[i];
		for(int f=0;f<n[i];f++)
		{
			for(int k=0;k<3;k++)
			{
				cin>>a[i][n[i]][k];
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		
		for(int f=0;f<n[i];f++)
		{
			for(int k=0;k<3;k++)
			{
				if(a[i][n[i]][k]>max)
				{
					max=a[i][n[i]][k];
				}	
			}
			c=c+max;
		}
		cout<<c;
	}
	return 0;
}
