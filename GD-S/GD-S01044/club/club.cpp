#include <bits/stdc++.h>
using namespace std;
int t,n,N,a[100005],b[100005],c[100005],h[4],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		N=n/2;
		ans=0;
		memset(h,0,sizeof(h));
		for (int j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
		}
		sort (a,a+n+1);
		for (int j=n;j>N;j--)
		{
			ans+=a[j];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
