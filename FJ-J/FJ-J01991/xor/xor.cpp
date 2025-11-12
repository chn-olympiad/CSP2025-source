#include <bits/stdc++.h>
using namespace std;
int n,k,a[100005],sum[100005],ans;
vector<pair<int,int> > v;
set<int> num;
bool cmp(pair<int,int> x,pair<int,int> y)
{
	return abs(x.second - x.first) < abs(y.second - y.first);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	sum[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = (sum[i - 1] xor a[i]);
	}
	for (int i = 1;i <= n;i++)
		for (int j = i;j <= n;j++)
			if ((sum[i - 1] xor sum[j]) == k)
			{
				v.push_back({i,j});
//				cout << sum[i - 1] << " " << sum[j]  << " " << (sum[i - 1] xor sum[j]) << endl;
			}
	sort(v.begin(),v.end(),cmp);
//	for (int i = 0;i < v.size();i++)
//		cout << v[i].first << " " << v[i].second << endl;
	for (int i = 0;i < v.size();i++)
	{
		if (num.empty())
		{
			for (int j = v[i].first;j <= v[i].second;j++)
				num.insert(j);
			ans++;
		}
		else
		{
			bool flag = true;
			for (int j = v[i].first;j <= v[i].second;j++)
				if (num.count(j) != 0)
				{
					flag = false;
					break;
				}
			if (flag)
			{
				for (int j = v[i].first;j <= v[i].second;j++)
					num.insert(j);
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
