#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	if(n==3)
	{
		int bj=a[1]+a[2]+a[3];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[3]))
		cout << 1;
		else cout << 0;
		return 0;
	}
	if(n==4)
	{
		int ans=0;
		int bj=a[1]+a[2]+a[3];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[3]))
		ans++;
		bj=a[1]+a[2]+a[4];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[4]))
		ans++;
		bj=a[1]+a[3]+a[4];
		if(bj>(2*a[1])&&bj>(2*a[3])&&bj>(2*a[4]))
		ans++;
		bj=a[2]+a[3]+a[4];
		if(bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[4]))
		ans++;
		bj=a[1]+a[2]+a[3]+a[4];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[4]))
		ans++;
		cout << ans;
		return 0;
	}
	if(n==5)
	{
		int ans=0;
		int bj=a[1]+a[2]+a[3];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[3]))
		ans++;
		bj=a[1]+a[2]+a[4];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[4]))
		ans++;
		bj=a[1]+a[2]+a[5];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[5]))
		ans++;
		bj=a[1]+a[3]+a[4];
		if(bj>(2*a[1])&&bj>(2*a[3])&&bj>(2*a[4]))
		ans++;
		bj=a[1]+a[3]+a[5];
		if(bj>(2*a[1])&&bj>(2*a[3])&&bj>(2*a[5]))
		ans++;
		bj=a[1]+a[4]+a[5];
		if(bj>(2*a[1])&&bj>(2*a[4])&&bj>(2*a[5]))
		ans++;
		bj=a[2]+a[3]+a[4];
		if(bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[4]))
		ans++;
		bj=a[2]+a[3]+a[5];
		if(bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[5]))
		ans++;
		bj=a[2]+a[4]+a[5];
		if(bj>(2*a[2])&&bj>(2*a[4])&&bj>(2*a[5]))
		ans++;
		bj=a[3]+a[4]+a[5];
		if(bj>(2*a[3])&&bj>(2*a[4])&&bj>(2*a[5]))
		ans++;
		bj=a[1]+a[2]+a[3]+a[4];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[4]))
		ans++;
		bj=a[1]+a[2]+a[3]+a[5];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[5]))
		ans++;
		bj=a[1]+a[2]+a[4]+a[5];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[4])&&bj>(2*a[5]))
		ans++;
		bj=a[1]+a[3]+a[4]+a[5];
		if(bj>(2*a[1])&&bj>(2*a[3])&&bj>(2*a[4])&&bj>(2*a[5]))
		ans++;
		bj=a[2]+a[3]+a[4]+a[5];
		if(bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[4])&&bj>(2*a[5]))
		ans++;
		bj=a[1]+a[2]+a[3]+a[4]+a[5];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[4])&&bj>(2*a[5]))
		ans++;
		cout << ans;
		return 0;
	}
	if(n==6)
	{
		int ans=0;
		int bj=a[1]+a[2]+a[3];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[3]))
		ans++;
		bj=a[1]+a[2]+a[4];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[4]))
		ans++;
		bj=a[1]+a[2]+a[5];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[5]))
		ans++;
		bj=a[1]+a[2]+a[6];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[6]))
		ans++;
		bj=a[1]+a[3]+a[4];
		if(bj>(2*a[1])&&bj>(2*a[3])&&bj>(2*a[4]))
		ans++;
		bj=a[1]+a[3]+a[5];
		if(bj>(2*a[1])&&bj>(2*a[3])&&bj>(2*a[5]))
		ans++;
		bj=a[1]+a[3]+a[6];
		if(bj>(2*a[1])&&bj>(2*a[3])&&bj>(2*a[6]))
		ans++;
		bj=a[1]+a[4]+a[5];
		if(bj>(2*a[1])&&bj>(2*a[4])&&bj>(2*a[5]))
		ans++;
		bj=a[1]+a[4]+a[6];
		if(bj>(2*a[1])&&bj>(2*a[4])&&bj>(2*a[6]))
		ans++;
		bj=a[1]+a[5]+a[6];
		if(bj>(2*a[1])&&bj>(2*a[5])&&bj>(2*a[6]))
		ans++;
		bj=a[2]+a[3]+a[4];
		if(bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[4]))
		ans++;
		bj=a[2]+a[3]+a[5];
		if(bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[5]))
		ans++;
		bj=a[2]+a[3]+a[6];
		if(bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[6]))
		ans++;
		bj=a[2]+a[4]+a[5];
		if(bj>(2*a[2])&&bj>(2*a[4])&&bj>(2*a[5]))
		ans++;
		bj=a[2]+a[4]+a[6];
		if(bj>(2*a[2])&&bj>(2*a[4])&&bj>(2*a[6]))
		ans++;
		bj=a[2]+a[5]+a[6];
		if(bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[4]))
		ans++;
		bj=a[3]+a[4]+a[5];
		if(bj>(2*a[3])&&bj>(2*a[4])&&bj>(2*a[5]))
		ans++;
		bj=a[3]+a[4]+a[6];
		if(bj>(2*a[3])&&bj>(2*a[4])&&bj>(2*a[6]))
		ans++;
		bj=a[3]+a[5]+a[6];
		if(bj>(2*a[3])&&bj>(2*a[5])&&bj>(2*a[6]))
		ans++;
		bj=a[4]+a[5]+a[6];
		if(bj>(2*a[4])&&bj>(2*a[5])&&bj>(2*a[6]))
		ans++;
		bj=a[1]+a[2]+a[3]+a[4];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[4]))
		ans++;
		bj=a[1]+a[2]+a[3]+a[5];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[5]))
		ans++;
		bj=a[1]+a[2]+a[3]+a[6];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[6]))
		ans++;
		bj=a[1]+a[2]+a[4]+a[5];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[4])&&bj>(2*a[5]))
		ans++;
		bj=a[1]+a[2]+a[4]+a[6];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[4])&&bj>(2*a[6]))
		ans++;
		bj=a[1]+a[2]+a[5]+a[6];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[5])&&bj>(2*a[6]))
		ans++;
		bj=a[1]+a[3]+a[4]+a[5];
		if(bj>(2*a[1])&&bj>(2*a[3])&&bj>(2*a[4])&&bj>(2*a[5]))
		ans++;
		bj=a[1]+a[3]+a[4]+a[6];
		if(bj>(2*a[1])&&bj>(2*a[3])&&bj>(2*a[4])&&bj>(2*a[6]))
		ans++;
		bj=a[1]+a[3]+a[5]+a[6];
		if(bj>(2*a[1])&&bj>(2*a[3])&&bj>(2*a[5])&&bj>(2*a[6]))
		ans++;
		bj=a[1]+a[4]+a[5]+a[6];
		if(bj>(2*a[1])&&bj>(2*a[4])&&bj>(2*a[5])&&bj>(2*a[6]))
		ans++;
		bj=a[2]+a[3]+a[4]+a[5];
		if(bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[4])&&bj>(2*a[5]))
		ans++;
		bj=a[2]+a[3]+a[4]+a[6];
		if(bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[4])&&bj>(2*a[6]))
		ans++;
		bj=a[2]+a[3]+a[5]+a[6];
		if(bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[5])&&bj>(2*a[6]))
		ans++;
		bj=a[2]+a[4]+a[5]+a[6];
		if(bj>(2*a[2])&&bj>(2*a[4])&&bj>(2*a[5])&&bj>(2*a[6]))
		ans++;
		bj=a[3]+a[4]+a[5]+a[6];
		if(bj>(2*a[3])&&bj>(2*a[4])&&bj>(2*a[5])&&bj>(2*a[6]))
		ans++;
		bj=a[1]+a[2]+a[3]+a[4]+a[5];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[4])&&bj>(2*a[5]))
		ans++;
		bj=a[1]+a[2]+a[3]+a[4]+a[6];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[4])&&bj>(2*a[6]))
		ans++;
		bj=a[1]+a[2]+a[3]+a[5]+a[6];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[5])&&bj>(2*a[6]))
		ans++;
		bj=a[1]+a[2]+a[4]+a[5]+a[6];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[4])&&bj>(2*a[5])&&bj>(2*a[6]))
		ans++;
		bj=a[1]+a[3]+a[4]+a[5]+a[6];
		if(bj>(2*a[1])&&bj>(2*a[3])&&bj>(2*a[4])&&bj>(2*a[5])&&bj>(2*a[6]))
		ans++;
		bj=a[2]+a[3]+a[4]+a[5]+a[6];
		if(bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[4])&&bj>(2*a[5])&&bj>(2*a[6]))
		ans++;
		bj=a[1]+a[2]+a[3]+a[4]+a[5]+a[6];
		if(bj>(2*a[1])&&bj>(2*a[2])&&bj>(2*a[3])&&bj>(2*a[4])&&bj>(2*a[5])&&bj>(2*a[6]))
		ans++;
		cout << ans;
		return 0;
	}
	int ans=1;
	for(int bj=1;bj<=n-3;bj++)
	{
		long long cnt1=1, cnt2=1;
		for(int i=1;i<=bj;i++)
		{
			cnt1*=i;
			cnt1%=mod;
		}
		for(int i=n;i>=n-bj+1;i--)
		{
			cnt2*=i;
			cnt2%=mod;
		}
		ans+=(cnt2/cnt1);
		ans%=mod;
	}
	cout << ans;
	return 0;
}