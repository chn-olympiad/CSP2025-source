# include <bits/stdc++.h>
using namespace std;
int n,a[5010],s[5010],maxn,l,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==1)
	ans=0;
	else if(n==2)
	{
		if(a[1]+a[2]>2*max(a[1],a[2]))
		ans++;
	}
	else if(n==3)
	{
		if(a[1]+a[2]>2*max(a[1],a[2]))
		ans++;
		if(a[1]+a[3]>2*max(a[1],a[3]))
		ans++;
		if(a[3]+a[2]>2*max(a[3],a[2]))
		ans++;
		l=max(a[3],a[2]);
		if(a[3]+a[2]+a[1]>2*max(a[1],l))
		ans++;
	}
	 
	 cout<<ans%998424353;
}