#include<bits/stdc++.h>
using namespace std;
int t, n, a[100005][4];
pair<int, int> f1[100005], f2[100005], f3[100005];
int cnt1 = 0, cnt2 = 0, cnt3 = 0, sum = 0;

bool cmp1(pair<int, int> x, pair<int, int> y)
{
	return (max(a[x.second][2], a[x.second][3]) - x.first) > (max(a[y.second][2], a[y.second][3]) - y.first);
}
bool cmp2(pair<int, int> x, pair<int, int> y)
{
	return (max(a[x.second][1], a[x.second][3]) - x.first) > (max(a[y.second][1], a[y.second][3]) - y.first);
}
bool cmp3(pair<int, int> x, pair<int, int> y)
{
	return (max(a[x.second][2], a[x.second][1]) - x.first) > (max(a[y.second][2], a[y.second][1]) - y.first);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= max(cnt1, max(cnt2, cnt3)); i++)
			f1[i].first = f1[i].second = f2[i].first = f2[i].second = f3[i].first = f3[i].second = 0;
		cnt1 = 0, cnt2 = 0, cnt3 = 0, sum = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][1] > a[i][2] && a[i][1] > a[i][3]) f1[++cnt1].first = a[i][1], f1[cnt1].second = i, sum += a[i][1];
			else if(a[i][2] > a[i][3]) f2[++cnt2].first = a[i][2], f2[cnt2].second = i, sum += a[i][2];
			else f3[++cnt3].first = a[i][3], f3[cnt3].second = i, sum += a[i][3];
		}
		if(cnt1 <= n/2 && cnt2 <= n/2 && cnt3 <= n/2)
			cout << sum << endl;
		else if(cnt1 > n/2)
		{
			sort(f1 + 1, f1 + cnt1 + 1, cmp1);
			for(int i = 1; i <= (cnt1 - n/2); i++)
				sum = sum - a[f1[i].second][1] + max(a[f1[i].second][2], a[f1[i].second][3]);
			cout << sum << endl;
		}
		else if(cnt2 > n/2)
		{
			sort(f2 + 1, f2 + cnt2 + 1, cmp2);
			for(int i = 1; i <= (cnt2 - n/2); i++)
				sum = sum - a[f2[i].second][2] + max(a[f2[i].second][1], a[f2[i].second][3]);
			cout << sum << endl;
		}
		else
		{
			sort(f3 + 1, f3 + cnt3 + 1, cmp3);
			for(int i = 1; i <= (cnt3 - n/2); i++)
				sum = sum - a[f3[i].second][3] + max(a[f3[i].second][2], a[f3[i].second][1]);
			cout << sum << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
