#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,b[10],a1,a2,a3;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			int a[n][3];
			for(int c=1;c<=3;c++)
			{
				cin>>a[j][c];
				
			}
			
			sort(a[j]+1,a[j]+4);
			b[i]=b[i]+a[j][3];
			//cout<<b[i]<<endl;
		}		
	}
	
	for(int i=1;i<=t;i++)
	{
		cout<<b[i]<<endl;
	}
	return 0;
}
