#include<bits/stdc++.h>
using namespace std;
long long a[100010][5],z,ans=0,maxxx=-1;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n,t;
	cin>>t;
	while(t--)
	{
		
		memset(a,0,sizeof(a));
		ans=0;
		maxxx=-1;
		z=0;
		cin>>n;
		if(n==2)
		{
			cin>>a[0][0]>>a[0][1]>>a[0][2]>>a[1][0]>>a[1][1]>>a[1][2];
			z=max(a[0][0]+a[1][1],a[0][0]+a[1][2]);
			z=max(z,a[0][1]+a[1][0]);
			z=max(z,a[0][1]+a[1][2]);
			z=max(z,a[0][2]+a[1][0]);
			z=max(z,a[0][2]+a[1][1]);
			cout<<z<<endl;
			continue;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>maxxx)
				{
					z=a[i][j];
					maxxx=a[i][j];
				}
			}
			maxxx=-1;
			ans+=z;
		}
		cout<<ans<<endl;
	}
	return 0;
}
