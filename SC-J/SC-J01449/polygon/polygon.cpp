#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
			cout<<1;
		else
			cout<<0;
	}
	if(n==4)
	{
		if(a[1]+a[2]+a[3]+a[4]>2*max(max(a[1],a[4]),max(a[2],a[3])))
			ans++;
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
			ans++;
		if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4])))
			ans++;
		if(a[4]+a[2]+a[3]>2*max(a[4],max(a[2],a[3])))
			ans++;
		cout<<ans;
	}
	return 0;
}