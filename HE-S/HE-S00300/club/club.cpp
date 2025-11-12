#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==2)
		{
			int s=max(a[1]+b[2],a[2]+b[1]);
			s=max(s,a[1]+c[2]);
			s=max(s,a[2]+c[1]);
			s=max(s,b[1]+c[2]);
			s=max(s,b[2]+c[1]);
			cout<<s<<endl;
		}
		else
		{
			int ans=0;

			int sh=n/2;
			int a1=0,b1=0,c1=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]>b[i]&&a[i]>c[i]&&a1<sh)
				{
					a1++;
					ans+=a[i];
				}
				if(b[i]>a[i]&&b[i]>c[i]&&b1<sh)
				{
					b1++;
					ans+=b[i];
				}
				if(c[i]>b[i]&&c[i]>a[i]&&c1<sh)
				{
					c1++;
					ans+=c[i];
				}
			}
		
			cout<<ans<<endl;
		}
			
	}
	return 0;
}
