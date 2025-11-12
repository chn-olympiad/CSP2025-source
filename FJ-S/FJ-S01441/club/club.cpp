#include <bits/stdc++.h>
using namespace std;
int ans;
int main()
{
	freeopen("club.in","r",stdin);
	freeopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,a1=0;
		cin>>n;
		int a[n],b[n],c[n*2+1],s1=0,s2=0,s3=0;
		for(int i=0;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
//			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])
//			{
//				b[i]=a[i][3];c[i]=3;s3++;
//			}
//			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
//			{
//				b[i]=a[i][2];c[i]=2;s2++;
//			}	
//			else if(a[i][1]>=a[i][3]&&a[i][1]>=a[i][2])
//			{
//				b[i]=a[i][1];c[i]=1;s1++;
//			}
		}
		for(int i=n+1;i<n;i++)
		{
			c[i]=a[i];
			c[n+i]=b[i];
		}
		long long n2=2*n+1;
		sort(c+1,c+n2);
		for(int i=1;i<=n/2;i++) ans+=c[i];
		cout<<ans<<endl;
	}
	return 0;
}
