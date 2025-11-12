#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 7;

int n;

ll ans;

int a[N][4];

struct Node{int val1, val2, id;} b[N];

bool vis[N];

int cnt[4];

void Sol()
{
	ans = 0;
	cnt[1] = cnt[2] = cnt[3] = 0;

	cin >> n;

	for(int i(1); i <= n; ++i)
		for(int j(1); j <= 3; ++j)
			cin >> a[i][j];

	for(int i(1); i <= n; ++i)
	{
		b[i].id = i;

		int tmp[5];
		tmp[1] = a[i][1], tmp[2] = a[i][2], tmp[3] = a[i][3];

		sort(tmp+1, tmp+4);

		b[i].val1 = tmp[3] - tmp[2];
		b[i].val2 = tmp[2] - tmp[1];
	}

	sort(b+1, b+1+n, [&](Node x, Node y)
	{
		if(x.val1 != y.val1)return x.val1 > y.val1;
		else if(x.val2 != y.val2)	return x.val2 > y.val2;
		else return max({a[x.id][1], a[x.id][2], a[x.id][3]}) > max({a[y.id][1], a[y.id][2], a[y.id][3]});
	});

	for(int i(1); i <= n; ++i)
	{
		int id = b[i].id;

		struct node{int val, id;} tmp[5];
		tmp[1] = node{a[id][1], 1};
		tmp[2] = node{a[id][2], 2};
		tmp[3] = node{a[id][3], 3};

		sort(tmp+1, tmp+4, [&](node x, node y){return x.val > y.val;});

		if(cnt[tmp[1].id] + 1 <= n/2)ans += tmp[1].val, cnt[tmp[1].id]++;
		else if(cnt[tmp[2].id] + 1 <= n/2)ans += tmp[2].val, cnt[tmp[2].id]++;
		else if(cnt[tmp[3].id] + 1 <= n/2)ans += tmp[3].val, cnt[tmp[3].id]++;
	}
	
	cout << ans << '\n';
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin.tie() -> ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while(T--)Sol();

	return 0;
}
