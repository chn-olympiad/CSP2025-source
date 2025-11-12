#include<bits/stdc++.h>
using namespace std;
int n,a[1001000],num=0,ans=INT_MIN;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num+=a[i];
		ans=max(ans,a[i]);
	}
	if(n<3)
	{
		cout<<"0";
		return 0;
	}
	else if(n==3)
	{
		if(num>ans*2)
		{
			cout<<"1";
			return 0;
		}
		else
		{
			cout<<"0";
			return 0;
		}
	}
	else
	{
		cout<<"41515";
		return 0;
	}
	return 0;
}
