#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[10000][5],x=0,sum=0;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++)
		{
			x=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>x)
				{
					x=a[i][j];
				}
			}
			sum+=x;
		}
		cout<<sum;
		
	
	}
	
	
	return 0;
}
