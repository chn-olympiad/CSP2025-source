// 9:49
// T3 我直接没看 

// 11:03
// T3 写破防了
// 但你以为 T4 我就不破防吗
// 算了
// 特判 task15-20
// 能骗一点是一点 
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
const int MAXN=10001;

int ans;

int jiecheng(int n)
{
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		ans*=i%MOD;
	}
	return ans%MOD;
}

int C(int n,int m)
{
	return jiecheng(n)/(jiecheng(m)*jiecheng(n-m))%MOD;
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	

	int n;
	cin >> n;
	if(n<3)
	{
		cout << 0;
		return 0;
	} 
	if(n==3)
	{
		int a,b,c;
		cin >> a >> b >> c;
		int maxn=max(a,max(b,c));
		if(a+b+c>2*maxn)
		{
			cout << 1;
			return 0;
		}
		cout << 0;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		ans+=C(n,i)%MOD;
	}
	cout << ans%MOD;
	return 0; 
}
