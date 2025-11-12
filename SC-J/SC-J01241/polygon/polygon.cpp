#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,a[5005],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	if(n!=3)
	{
		for(long long i=2;i<=n;i++)
			for(long long j=n-i;j>0;j--)
			{
				ans+=j;
				ans%=MOD;
			}
	}
	else
	{
		int mx=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			cnt+=a[i];
			if(a[i]>=mx)
				mx=a[i];
		}
		if(cnt>2*mx)
			ans=1;
		else
			ans=0;
		
	}
	cout<<ans;
	return 0;
}