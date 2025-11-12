#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int a[100050],b[100050],c[100005];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>t;
	int shu=0;
	for(int j=1;j<=t;j++)
	{
		int ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1,greater<int>());
		for(int i=1;i<=n/2;i++)
		{
			ans=ans+a[i];
		}
		cout<<ans;
	}
	return 0;
}
