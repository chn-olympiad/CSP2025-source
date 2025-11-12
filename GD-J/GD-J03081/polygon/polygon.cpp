#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long ksm(long long a,long long b)
{
	long long ans = 1;
	while(b)
	{
		if(b & 1)
		{
			ans = ans % mod * a % mod;
		}
		a = a % mod * a % mod;
		b >>= 1;
	}
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[5005];
	int n;
	cin>>n;
	long long ans =0;
	memset(a,0,sizeof(a));
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a + 1,a + n + 1);
	if(n <= 3)
	{
		if(a[1] + a[2] + a[3] > 2*a[3])
		{
			cout<<1<<"\n"; 
		}
		else
		{
			cout<<0<<"\n";
		}
	}
	else
	{
		cout<<(ksm(2,n) % mod - 1-n-(n*n-n) / 2 + mod) % mod<<"\n";
	}
	return 0;
}

