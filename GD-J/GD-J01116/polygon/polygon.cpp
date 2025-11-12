#include <bits/stdc++.h>
using namespace std;

long long n;
long long num[50005];

long long max(long long a,long long b){return a > b?a : b;}

long long dg(long long a,long long b,long long maxs)
{
	long long t = 0;
	if (a > maxs * 2) t ++;
	if (b + 1 > n) return t;
	for (long long i = b + 1;i <= n;i++)
		t = (dg(a + num[i],i,max(maxs,num[i])) + t) % 998244353;
	return t;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (long long i = 1;i <= n;i++)
		cin >> num[i];
	cout << dg(0,0,0) << endl;
	return 0;
}
