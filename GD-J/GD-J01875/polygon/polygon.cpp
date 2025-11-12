#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,a[4];
	cin>>n;
	if(n==1)
	{
		cin>>a[1];
		cout<<0;
	}
	else if(n==2)
	{
		cin>>a[0]>>a[1];
		cout<<0;
	}
	else if(n==3)
	{
		cin>>a[0]>>a[1]>>a[2];
		if(a[1]+a[0]>a[2]&&a[1]+a[2]>a[0]&&a[0]+a[2]>a[1])
		cout<<1;
		else cout<<0;
	}
	else if(n==4)
	{
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		int sum=0;
		if(a[1]+a[0]>a[2]&&a[1]+a[2]>a[0]&&a[0]+a[2]>a[1])sum++;
		if(a[3]+a[0]>a[2]&&a[3]+a[2]>a[0]&&a[0]+a[2]>a[3])sum++;
		if(a[1]+a[0]>a[3]&&a[1]+a[3]>a[0]&&a[0]+a[3]>a[1])sum++;
		if(a[1]+a[3]>a[2]&&a[1]+a[2]>a[3]&&a[3]+a[2]>a[1])sum++;
		if(a[0]>a[1]&&a[0]>a[2]&&a[0]>a[3])
		if(a[1]+a[2]+a[3]+a[0]>a[0]*2)return cout<<sum+1,0;
		else return cout<<sum,0;
		if(a[1]>a[0]&&a[1]>a[2]&&a[1]>a[3])
		if(a[0]+a[2]+a[3]+a[1]>a[1]*2)return cout<<sum+1,0;
		else return cout<<sum,0;
		if(a[2]>a[0]&&a[2]>a[1]&&a[2]>a[3])
		if(a[0]+a[1]+a[3]+a[2]>a[2]*2)return cout<<sum+1,0;
		else return cout<<sum,0;
		if(a[3]>a[0]&&a[3]>a[1]&&a[3]>a[2])
		if(a[0]+a[1]+a[2]+a[3]>a[3]*2)return cout<<sum+1,0;
		else return cout<<sum,0;
	}
	else cout<<0;
	return 0;
}

