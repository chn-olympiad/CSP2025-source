#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005],b[10005],c[10005],d[10005],e[10005],f[10005];
int main()
{
	freopen("club.in,"r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	int x=1,y;
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[x]>>b[x]>>c[x];
			x++;
		}
		if(b[1]==0&&c[1]==0)
		{
			int sum=0;
			sort(a+1,a+1+n);
			y=n/2+1;
			for(int z=y;z<=n;z++)
			{
				sum+=a[z];
			}
			cout<<sum<<endl;
		}
		if(n==4)
		{
			int ans=0;
			for(int j=1;j<=n;j++)
			{
				d[j]=a[j];
				e[j]=b[j];
				f[j]=c[j];
			}
			sort(d+1,d+1+n);
			sort(e+1,e+1+n);
			sort(f+1,f+1+n);
			ans=d[n]+e[n]+f[n]+max(d[n-1],max(e[n-1],f[n-1]));
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
