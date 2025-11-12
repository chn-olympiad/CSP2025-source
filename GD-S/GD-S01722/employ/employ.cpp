#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long inv[2000005] = {1},t[2000005] = {1},sum;
long long pows(long long a,long long b)
{
	if(b == 0) return 1;
	long long t=pows(a,b/2);
	if(b&1)return t * t*a%998244353;
	return t*t%998244353;
}
long long C(int n,int m)
{
	return t[n] * inv[n - m] % mod * inv[m] % mod;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		t[i]  =t[i - 1]*i%mod,inv[i] = pows(t[i],998244351);
	for(int i = m; i <= n; i++)
		sum = (sum + C(n,m)) % 998244353;
	cout << sum;
}
