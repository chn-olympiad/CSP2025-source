#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
const long long mod = 998244353;
long long a[5005];
long long mp[25000005];
long long n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long i, j, ans = 0, tot = 1, temp, sum=0;
	cin >> n;
	for(i = 1; i <= n; i++)
		cin >> a[i], sum += a[i];
	stable_sort(a+1,a+1+n);
	mp[a[1] + a[2]] = 1;
	for(i = 3; i <= n; i++)
	{
		temp = 0;
		for(j = 1; j <= a[i]; j++)
		{
			temp = (temp + mp[j]) % mod;
		}
		ans = (ans + (tot - temp + mod) % mod) % mod;
		for(j = sum - a[i]; j; j--)
			if(mp[j])
				mp[a[i] + j] = (mp[a[i] + j] + mp[j]) % mod, tot = (tot + mp[j]) % mod;
		for(j = 1; j < i; j++)
			mp[a[i] + a[j]] = (mp[a[i] + a[j]] + 1) % mod, tot = (tot + 1) % mod;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
