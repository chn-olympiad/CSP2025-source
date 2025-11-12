#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,b[505],dp[505],num=0;
	char a[505];
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=0;i<n;i++)
	{
		if(a[i]=='1')num++;
	}
	cout<<" "<<num<<endl;
	if(num<m)
	{
		cout<<0;
	}
	else if(num>=m)
	{
		dp[0]=0;dp[1]=1;dp[2]=2;
		for(int i=3;i<=num;i++)
		{
			dp[i]=i*dp[i-1]%998244353;
		}
		cout<<dp[num]%998244353;
	}

	return 0;
}
