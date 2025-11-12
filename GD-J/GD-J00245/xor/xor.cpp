#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n , k;
int a[N];
int sum[N];
int K[N];
unordered_map<int , int> mp;
int s[N];
bool vis[N];
int ans;
int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (i != 1)
		{
			mp[sum[i - 1]] = true;
			sum[i] = sum[i - 1] ^ a[i]; 
		}else
		{
			sum[i] = a[i];
		}
		K[i] = a[i] ^ k;
		s[i] = sum[i - 1] ^ k;
		if (K[i] == 0)
		{
			vis[i] = true;
			ans++;
		}
	}
//	cout << ans << endl;
	int i = 1;
	for (; i <= n;)
	{
		int S = 0;
		bool f = false;
		int id = i + 1;
		if (vis[i]){
			i = id;
			continue;
		}
		for (int j = i; j <= n; ++j)
		{
			if (vis[j]){
				break;
			}
			S ^= a[j];
			if (S == k)
			{
				id = j + 1; 
				f = true;
				break;
			}
		}
		if (f)
		{
//			cout << i << " " <<id << endl;
			ans++;
		}
		i = id;
	}
	cout << ans;
//	for (int i = 1; i <= n; ++i)
//	{
//		cout << s[i] << " ";
//		for (int j = i; j <= n; ++j)
//		{
//			int k = sum[j] ^ sum[i - 1];
//			cout << k << " ";
//		}
//		cout << endl;
//	}
	return 0;
}
/*
4 2
2 1 0 3

4 0
2 1 0 3
	int r;
	int l = 1;
	for(; l < n;)
	{
		if (vis[l])continue;
		r = l;
		bool f = false;
		while (r <= n)
		{
			r++;
			if (vis[r]) break;
			if (l == 1)
			{
				if (sum[r] == k)
				{
					f = true;
					break;
				}
			}else if (sum[r] ^ sum[l - 1] == k)
			{
				f = true;
				break;
			}
		}
		if (f)
		{
//			cout << l << " " << r << endl;
			ans++;
			l = r + 1;
		}else
		{
			l++;
		}
	}
*/
