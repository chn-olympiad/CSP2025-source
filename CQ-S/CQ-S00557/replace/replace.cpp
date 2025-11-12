/* expect : 60 + [0, 40] pts */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
using namespace std;

bool ST;

const int N = 200010, V = 5000010;
int n, m;
string org_s[N][2], org_t[N][2], s[N], t[N];
inline string work(string A, string B)
{
	string res = "";
	for(int i = 0; i < (int)A.size(); ++i)
		res += A[i], res += B[i];
	return res;
}

int fail[V], tr[V][26], idx = 1;
struct node {int id, lim;};
vector < int > sve[V]; vector < node > tmp[V]; queue < int > q;

long long res[N]; vector < int > edge[V];
struct BIT
{
	int c[V], len = 5e6;
	inline void add(int pos, int num)
	{for(int i = pos; i <= len; i += lowbit(i)) c[i] += num;}
	inline int ask(int pos)
	{
		int res = 0;
		for(int i = pos; i; i -= lowbit(i)) res += c[i];
		return res;
	}
	inline int query(int l, int r) {return ask(r) - ask(l - 1);}
}; BIT bit;

inline void treedp(int pos, int prt)
{
	for(int x : sve[pos]) bit.add(x, 1);
	for(node nd : tmp[pos])
		res[nd.id] += bit.query(nd.lim, 5000000);
	for(int to : edge[pos]) treedp(to, pos);
	for(int x : sve[pos]) bit.add(x, -1);
}

bool ED;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	// cerr << "Memory : " << (&ST - &ED) / 1024.0 / 1024.0 << '\n';
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
	{
		cin >> org_s[i][0] >> org_s[i][1];
		s[i] = work(org_s[i][0], org_s[i][1]);
	}
	for(int i = 1; i <= m; ++i)
	{
		cin >> org_t[i][0] >> org_t[i][1];
		t[i] = work(org_t[i][0], org_t[i][1]);
	}
	
	for(int i = 1; i <= n; ++i)
	{
		int p = 1;
		for(char c : s[i])
		{
			if(!tr[p][c - 'a']) tr[p][c - 'a'] = ++idx;
			p = tr[p][c - 'a'];
		}
		sve[p].push_back(s[i].length());
	}
	q.push(1);
	while(!q.empty())
	{
		int pos = q.front(); q.pop();
		for(int i = 0; i < 26; ++i)
		{
			if(!tr[pos][i]) continue;
			int to = tr[pos][i];
			fail[to] = fail[pos];
			while(fail[to] && !tr[fail[to]][i]) fail[to] = fail[fail[to]];
			if(!fail[to]) fail[to] = 1;
			else if(tr[fail[to]][i]) fail[to] = tr[fail[to]][i];
			q.push(to);
		}
	}

	// for(int i = 1; i <= idx; ++i) cerr << fail[i] << " ";
	// cerr << '\n';

	for(int i = 1; i <= idx; ++i) if(fail[i]) edge[fail[i]].push_back(i);

	for(int i = 1; i <= m; ++i)
	{
		int len = t[i].length(); t[i] = ' ' + t[i];
		int L = 0, R = 0;
		for(int j = 1; j <= len; j += 2)
		{
			if(t[i][j] != t[i][j + 1])
			{
				if(!L) L = j;
				R = j + 1;
			}
		}

		int pt = 1;
		for(int j = 1; j <= len; ++j)
		{
			while(pt && !tr[pt][t[i][j] - 'a']) pt = fail[pt];
			if(!pt) pt = 1;
			if(tr[pt][t[i][j] - 'a']) pt = tr[pt][t[i][j] - 'a'];
			if(R <= j && j % 2 == 0)
			{
				tmp[pt].push_back({i, j - L + 1});
			}
		}
	}
	treedp(1, 0);
	for(int i = 1; i <= m; ++i) cout << res[i] << '\n';
	return 0;
}
/*
g++ replace.cpp -o replace -O2 -std=c++14 -static -Wall -DLOCAL -Wno-unused-result
./replace
*/
