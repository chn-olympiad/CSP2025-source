#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
int n, k, ans;
int a[500005], b[500005];
vector<pair<int ,int>> v;


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	mt19937 rng((unsigned long long)(new char));
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[i] = b[i-1] ^ a[i];
	}
	
	int tail = 0;
	for(int i = 1;i <= n;i++)
	{
		bool f = false;
		for(int j = i;j > tail;j--)
		{
			if((b[i]^b[j-1]) == k)
			{
				f = true;
				break;
			}
		}
		if(f)
		{
			tail = i;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
