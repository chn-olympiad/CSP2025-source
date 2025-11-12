#include<iostream>
#include<algorithm>
#define lowbit(x) (x & (-x))
using namespace std;
const int mod = 998244353;
int n,a[5010],maxl = -1,s,c[5010];
int f[5010],invf[5010];
int qpow(int x,int n)
{
	int res = 1;
	while(n)
	{
		if(n & 1)
			res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		n >>= 1;
	}
	return res;
}
int lg[5010],st[5010][15];
long long cnt;
void init1()
{
	lg[1] = 0;
	for(int i = 2;i <= n;i++)
		lg[i] = lg[i / 2] + 1;
	for(int i = 1;i <= n;i++)
		st[i][0] = a[i];
	for(int k = 1;k <= lg[n];k++)
		for(int i = 1;i + (1 << k) - 1 <= n;i++)
			st[i][k] = max(st[i][k - 1],st[i + (1 << (k - 1))][k - 1]);
}
void add(int x,int k)
{
	while(x <= n)
		c[x] += k,
		x += lowbit(x);
}
int getsum(int x)
{
	int sum = 0;
	while(x > 0)
	{
		sum += c[x];
		x -= lowbit(x);
	}
	return sum;
}
int getmax(int l,int r)
{
	int k = lg[r - l + 1];
	return max(st[l][k],st[r - (1 << k) + 1][k]);
}
void init()
{
	f[1] = f[0] = invf[0] = 1;
	for(int i = 2;i <= 5000;i++)
		f[i] = 1ll * f[i - 1] * i % mod;
//		cout << f[i] << ' ';
	invf[5000] = qpow(f[5000],mod - 2);
	for(int i = 4999;i >= 1;i--)
		invf[i] = 1ll * invf[i + 1] * (i + 1) % mod;
//		cout << invf[i] <<' ';
}
int comb(int n,int m)
{
	return 1ll * f[n] * invf[n - m] % mod * invf[m] % mod;
}
int main()
{
	init();
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i],maxl = max(maxl,a[i]),s += a[i];
//		add(i,a[i]),add(i + 1,-a[i]);
//	init1();
//	for(int i = 1;i <= n;i++)
//		cout << c[i] << ' ';
	if(n <= 2)
	{
		cout << 0;
		return 0;
	}
//	for(int i = 1;i <= n;i++)
//		cout << getsum(i) << ' ';
//	for(int l = 3;l <= n;l++)
//	{
//		for(int i = 1;i + l - 1 <= n;i++)
//		{
//			int j = i + l - 1;
//			if(getsum(j) - getsum(i - 1) > getmax(i,j))
//			{
//				cout <<i << ' ' << j <<'\n';
//				cnt++;
//			}
//		}
//	}
	if(n == 3)
	{
		if(s > 2 * maxl)
		{
			cout << 1;
			return 0;
		}
		else
		{
			cout << 0;
			return 0; 
		}
	}
	if(maxl == 1)
	{
		long long ans = 0;
		for(int l = 3;l <= n;l++)
			ans = ans + comb(n,l) % mod;
		cout << ans;
		return 0;
	}
	cout << cnt;
	return 0;
}
