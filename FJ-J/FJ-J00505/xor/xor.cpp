#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N = 5e5 + 5;

int n, k, a[N];
int s[N], ans;

signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
			if((s[j] ^ s[i - 1]) == k)
				i = j + 1, ans++;
	cout << ans << endl;
	return 0;
}














