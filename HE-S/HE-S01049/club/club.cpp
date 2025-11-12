#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[20010],b[20010],c[20010];
void solve()
{
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int mx=INT_MIN;
		cin>>a[i]>>b[i]>>c[i];
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	sort(c+1,c+1+n);
	for(int i=n;i>=n/2;i--)
	{
		sum+=a[i];
	}
	cout<<sum<<endl;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
