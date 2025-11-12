#include <bits/stdc++.h> 
using namespace std;
int n,a[5005];
bool x=true; 
int ans;
int sum(int n1,int i1)
{
	if(i1+1<n)
		return (n-i1)*(n-i1-1)/2+sum(n1,i1+1);
	else
		return 0;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]!=1)
			x=false;
	}
	if(n<3)
	{
		cout << 0;
	}
	else if(n==3)
	{
		if((a[1]+a[2]+a[3])>=2*(max(a[1],max(a[2],a[3]))))
		{
			cout << 1;
		}
		else
			cout << 0;
	}
	else if(x)
	{
		for(int i=3;i<=n;i++)
		{
			ans=(ans+sum(n,i-2))%998244353;
		}
		cout << ans;
	}
	return 0;
}