#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a[120];
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int xb,ak=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(ak==a[i])
		{
			xb=i;
			break;
		}
	}//n是行，m是列 
	if(m==1)
	{
		return cout<<1<<' '<<xb,0;
	}
	if(n==1)
	{
		return cout<<xb<<' '<<1,0;
	}
	int lie=(xb%n==0?xb/n:xb/n+1);
	cout<<lie<<' ';
	if(lie%2)
	{
		if(xb%n==0)
		cout<<n;
		else if((xb-1)%n==0)
		cout<<1;
		else
		cout<<xb-(lie-1)*n+1;
	}
	else
	{
		if(xb%n==0)
		cout<<1;
		else if((xb-1)%n==0)
		cout<<n;
		else
		cout<<n-(xb-(lie-1)*n)+1;
	}
	return 0;//rp++
} 
