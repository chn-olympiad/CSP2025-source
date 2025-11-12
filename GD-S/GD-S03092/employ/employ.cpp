#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 998244353;
int n,m,T,ans,cnt;
string s;
int a[506],c[506],num[506],sum[506];
bool cmp(int x,int y)
{
	return x > y;
}
void solve()
{
	sort(c+1,c+1+n,cmp);
	for(int i=0;i<T;i++)
	{
		if(s[i] == '0') num[i+1] = num[i] + 1;
		else num[i+1] = num[i];
	}
	if(m == 1)
	{
		for(int i=T;i>=1;i--)
		{
			for(int j=1;j<=n;j++)
				if(num[j] < c[j]) ans = (ans+sum[n-1])%N;
		}
		ans /= 2;
		printf("%lld",ans);
		return ;
	}
	if(m == n)
	{
		ans = 1;
		for(int i=T;i>=1;i--)
		{
			for(int j=1;j<=n;j++)
				if(num[j] < c[j]) cnt++;
			ans = (ans * (cnt-i+1))%N;
		}
		printf("%lld",ans);
		return ;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin >> s;
	T = s.size();
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(int i=0;i<T;i++)
	{
		if(s[i] == '0')
		{
			solve();
			return 0;
		}
	}
	sum[0] = 1;
	for(int i=1;i<=n;i++) sum[i] = (sum[i-1] * i)%N;
	printf("%lld",sum[n]);
	return 0;
}
