#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int a[N], prefix[N];
bool custom_Cmp(pair <int, int> x, pair <int, int> y)
{
	if (x.second < y.second)
	{
		return 1;
	}
	else if (x.second == y.second)
	{
		return x.first > y.first;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector <pair <int, int>> tmp;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if (i == 0)
		{
			prefix[i] = a[i];
		}
		else
		{
			prefix[i] = a[i] ^ prefix[i - 1];
		}
	}
//	for (int i = 1; i <= n; i ++)
//	{
//		cout << prefix[i] << " ";
//	}
	//cout << endl;
	for (int i = 0; i <= n; i ++)
	{
		for (int j = (i == 0) ? 1 : i; j <= n; j ++)
		{
			if ((prefix[i] ^ prefix[j]) == k && i + 1 < j)
			{
				tmp.push_back({i + 1, j});
			}
			else if (i == j && a[i] == k)
			{
				tmp.push_back({i, j});
			}
		}
	}
	int vct_sz = tmp.size();
	sort(tmp.begin(), tmp.end(), custom_Cmp);
	pair <int, int> tmp2 = tmp[0];
	int lst = tmp2.second, ans = 1;
	//cout << tmp2.first << " " << tmp2.second << endl;
	for (int i = 1; i < vct_sz; i ++)
	{
		pair <int, int> cur = tmp[i];
		//cout << cur.first << " " << cur.second << endl;
		if (cur.first <= lst)
		{
			//cout << cur.first << " <= " << lst << endl;
			continue;
		}
		else
		{
			ans ++;
		}
		lst = cur.second;
	}
	//cout << tmp.size() << endl;
	cout << ans << endl;
	return 0;
}