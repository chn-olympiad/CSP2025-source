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

const int N = 1e4+25;

int n ,m, k;

int f[N];
int c[N],a[15][N];
array<int,3> e[N * 200];
int siz[N];
//vector<array<int,3> > v[15];
int find(int x)
{
	if (f[x] != x) 
	f[x ] = find(f[x]);
	return f[x];
}

void mg(int x,int y)
{
	x= find(x),y= find(y);
	if (siz[x] > siz[y]) swap(x,y);
	f[x] = y;
}

void solvemain()
{
	cin >> n >> m >> k;
	rep(i,1,n) f[i] = i,siz[i] = 1;
	vector<array<int,3> > g;
	rep(i,1,m)
	{
		int x,y,cc;
		cin >> x >> y >> cc;
		e[i] = {cc,x,y};
	}
	sort(e+ 1,e+ m + 1);
	for (int i = 1;i <= m;i++)
	{
		if (find(e[i][1]) == find(e[i][2])) continue;
//		f[find(e[i][1])] = find(e[i][2]);
		mg(e[i][1],e[i][2]);
		g.pb(e[i]);
	}
	rep(i,1,n) f[i ] = i,siz[i] = 1;
	rep(i,1,k)
	{
		cin >> c[i];
		rep(j,1,n) 
		{
			cin >> a[i][j];
//			v[i].pb({a[i][j],j,i + n});
		}
//		sort(all(v[i]));/
	}	
//	return;
	ll ans = 9e18;
	
	for (int st = 0;st < (1<<k);st++)
	{
		bool flag = 0;
		for (int i = 0;i < k;i++)
			if ((st >> i & 1)==0 && c[i + 1] == 0) flag = 1;
		if (flag) continue;
		int nsz = g.size();
		ll res = 0;
		for (int i = 0;i < k;i++)
			if (st >> i & 1)
			{
				res += c[i + 1];
				rep(j,1,n) g.pb({a[i + 1][j],i + 1 + n,j});
			}
		sort(all(g));
		rep(i,1,n + k) f[i] = i,siz[i] = 1;
		
		for (auto it : g)
		{
			if (find(it[1]) == find(it[2])) continue;
			mg(it[1],it[2]);
			res += it[0];
		}
		ans = min(ans,res);
//		cout << g.size() << endl;
		g.resize(nsz);
//		cout << g.size() << endl;
//		cerr <<st<< endl;
	}
	cout << ans << endl;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t ;t = 1;
	while (t--) {
		solvemain();
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
