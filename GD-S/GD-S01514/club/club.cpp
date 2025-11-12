#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 0x3f3f3f3f
#define PII pair<int,int>
#define rep(k,a,b) for (int k = a;k <= b;k++)
#define all(a) a.begin(),a.end()
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define vct vector
#define endl '\n'
#define sz(a) ((int)a.size())
#define rof(k,a,b) for (int k = a;k >= b;k--)

void solvemain()
{
	int n;cin >> n;
	vector<array<int,3> > a(n + 2);
	vector<vector<int> > v(4);
	ll ans = 0;
	rep(i,1,n)
	{
		int mx = -INF,fg = -1;
		rep(j,0,2) 
		{
			cin >> a[i][j];
			if (a[i][j] > mx) 
			{
				mx = a[i][j];fg =j;
			}
		}
		ans += mx;
		sort(all(a[i]));
		v[fg].pb(a[i][2] - a[i][1]);
	}
	for (int j = 0;j < 3;j++)
	{
		if (sz(v[j]) > n / 2)
		{
			sort(all(v[j]));
			int t = sz(v[j]) - n/ 2;
			for (int i = 0;i < t;i++)
				ans -= v[j][i];
		}
	}
	cout << ans << endl;
	
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t ;t = 1;cin >> t;
	while (t--) {
		solvemain();
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

