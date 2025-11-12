//GZ-S00098 贵阳市第一中学 周也迪 
#include<bits/stdc++.h>
using namespace std;
int t;
int n,a[500005],b[500005],c[500005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i];
		if(n==2)
		{
			int d[6];
			d[1]=a[1]+b[2];d[2]=a[1]+c[2];
			d[3]=b[1]+a[2];d[4]=b[1]+c[2];
			d[5]=c[1]+a[2];d[6]=c[1]+b[2];
			sort(d+1,d+6+1);
			cout<<d[6]<<endl;
		}
		else
		{
			sort(a,a+n+1);
			for(int i=n/2+1;i<=n;i++)
				ans+=a[i];	
			cout<<ans<<endl;
		}
	}
	return 0;
}
