#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int N = 1e5 + 5;

int a[N][5], sum, n;
vector<int> s(5);
bool cmp(P x, P y) {return x.first > y.first;}
int pick_max(int a, int b, int c)
{
	vector<P> tp;
	tp.emplace_back(a, 1);
	tp.emplace_back(b, 2);
	tp.emplace_back(c, 3);
	sort(tp.begin(), tp.end(), cmp);
	return tp[0].second;
}
int pick_mid(int a, int b, int c)
{
	vector<P> tp;
	tp.emplace_back(a, 1);
	tp.emplace_back(b, 2);
	tp.emplace_back(c, 3);
	sort(tp.begin(), tp.end(), cmp);
	return tp[1].second;
}
void move(int id)
{
	vector<int> diff;
	for (int i = 1; i <= n; i++)
	{
		if (pick_max(a[i][1], a[i][2], a[i][3]) == id)
		{
			int maxn = a[i][pick_max(a[i][1], a[i][2], a[i][3])];
			int midn = a[i][pick_mid(a[i][1], a[i][2], a[i][3])];
			diff.push_back(maxn - midn);	
//			cout << maxn << ' ' << midn << '\n';
		}	
//		cout << "666\n";
	}
//	for (auto i : diff) cout << i << ' ';
//	cout << '\n';
	int num = s[id] - n / 2;
	sort(diff.begin(), diff.end());
	for (int i = 0; i < num; i++) sum -= diff[i];
}

void solve()
{
	sum = 0;
	s[1] = s[2] = s[3] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		s[pick_max(a[i][1], a[i][2], a[i][3])]++;
		sum += a[i][pick_max(a[i][1], a[i][2], a[i][3])];
	}
//	cout << s[1] << ' ' << s[2] << ' ' << s[3] << '\n';
	for (int i = 1; i <= 3; i++)
		if (s[i] > n / 2)
			move(i);
	
	cout << sum << '\n';
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
