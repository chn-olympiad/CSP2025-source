#include <bits/stdc++.h>
using namespace std;

int n,m;
int mo=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	if(n<=3)
	{
		if(n<3)
		{
			cout<<0;
			return 0;
		}
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b+c>max(a,max(b,c)))
			cout<<1;
		else cout<<0;
		return 0;
	}
	long long ans=0;
	for(int i=n;i>=3;i--)
	{
		long long ak=1;
		for(int j=n;j>i;j--)
		{
			ak*=j/(n-j+1);
			ak%=mo;
		}
		ans+=ak;
		ans%=mo;
	}
	cout<<ans;
	return 0;
}
