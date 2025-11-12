#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k;
const int maxn = 5e5+10;
ll num[maxn];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> num[i];
	int ans = 0; int tmp = 0;
	int l = 1; tmp = num[1];
	for(int i=1; i<=n; i++)
	{
		if(tmp == k) 
		{
			ans++, l = i+1, tmp = num[l];
			continue;
		}
		tmp = tmp xor num[i+1];
		if(tmp > k) tmp = tmp xor num[l], l++;
	}
	cout << ans << endl;
	return 0;
} 