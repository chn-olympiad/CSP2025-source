#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	while(t--)
	{
		cin>>n;
		int a[n][3];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
			}
		}
		int maxx=-100000;
		if(n==2)
		{
			cout<<max(a[0][0]+a[1][1],max(a[0][0]+a[1][2],max(a[0][1]+a[1][0],max(a[0][1]+a[1][2],max(a[0][2]+a[1][0],a[0][2]+a[1][1])))));
		}
	}
	return 0;
}
