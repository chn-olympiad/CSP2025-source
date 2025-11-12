#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int a[114514][5],t,q,w;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int p=1;p<=t;p++)
	{
		ans=0;
		cin>>n;
		if(n==2)
		{
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		cout<<max(max(max(a[1][1]+a[2][2],a[1][1]+a[2][3]),max(a[1][2]+a[2][1],a[1][2]+a[2][3])),max(a[1][3]+a[2][1],a[1][3]+a[2][2]));
		cout<<endl;
		}
		else	
		{		
			for(int i=1;i<=n;i++)
				scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);	
			for(int i=1;i<=n;i++)
				a[i][4]=a[i][1]-a[i][2],a[i][0]=i;
			for(int i=1;i<=n;i++)
				for(int j=1;j<n;j++)
				{
					if(a[j][4]<a[j+1][4]) 
					{
						w=a[j][0],q=a[j][4],a[j][0]=a[j+1][0],a[j][4]=a[j+1][4];
						a[j+1][4]=q,a[j+1][0]=w;
					}
				}
			for(int i=1;i<=n/2;i++)
				ans+=a[a[i][0]][1];
			for(int i=n/2+1;i<=n;i++)
				ans+=a[a[i][0]][2];
			cout<<ans<<endl;
		}
	}
}
