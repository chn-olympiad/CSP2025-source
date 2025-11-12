#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int ans=a[1];
	sort(a+1,a+1+n*m);
	int d=upper_bound(a+1,a+1+n*m,ans)-a-1;
	d=n*m-d+1;
	int s=d/n;
	if(s&1)
	{
		if(d%n==0)
			cout<<s<<" "<<n;
		else
			cout<<s+1<<" "<<n-d%n+1;	
	}
	else
	{
		if(d%n==0)
			cout<<s<<" "<<1;
		else
			cout<<s+1<<" "<<d%n;	
	}
	return 0;
}
