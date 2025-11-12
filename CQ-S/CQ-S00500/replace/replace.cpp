#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
const int mod = 1e9 + 7;
int n, q;
string s1[maxn], s2[maxn], s3[maxn], s4[maxn];
int len[maxn], Len[maxn];
vector<int> Has1[maxn], Has2[maxn], Has3[maxn], Has4[maxn];
int p[5000005];
int get1(int i, int l, int r)
{
	if(l == 0) return Has1[i][r];
	return (Has1[i][r] - Has1[i][l - 1] * 1ll * p[r - l + 1] % mod + mod) % mod;
}
int get2(int i, int l, int r)
{
	if(l == 0) return Has2[i][r];
	return (Has2[i][r] - Has2[i][l - 1] * 1ll * p[r - l + 1] % mod + mod) % mod;
}
int get3(int i, int l, int r)
{
	if(l == 0) return Has3[i][r];
	return (Has3[i][r] - Has3[i][l - 1] * 1ll * p[r - l + 1] % mod + mod) % mod;
}
int get4(int i, int l, int r)
{
	if(l == 0) return Has4[i][r];
	return (Has4[i][r] - Has4[i][l - 1] * 1ll * p[r - l + 1] % mod + mod) % mod;
}
int num;
int trie[5000005][26], tot;
int l[maxn], r[maxn];
int ll[maxn], rr[maxn];
struct node
{
	int val1, val2, id;
	bool flg;
	bool operator <(const node &n)const
	{
		return val1 < n.val1 || (val1 == n.val1 && val2 < n.val2);
	}
}arr[maxn * 2];
int ans[maxn];
int id1[maxn], id2[maxn], tot1, tot2;
vector<int> Exit[5000005];
void ins1(int i, int j)
{
	int now = 0;
	for (int k = j; k >= 0; --k)
	{
		int x = s1[i][k] - 'a';
		if(!trie[now][x]) trie[now][x] = ++tot;
		now = trie[now][x];
	}
	Exit[now].push_back(i);
}
bool cmp(int x, int y)
{
	return len[x] - r[x] < len[y] - r[y];
}
unordered_map<int, int> bucket[5000005], Real[5000005], tar[5000005]; 
int belong[maxn];
void solve()
{
	if(!tot2) return;
	tot = 0;
//	for (int i = 1; i <= tot1; ++i) cout << id1[i] << " ";
//	cout << endl;
//	for (int i = 1; i <= tot2; ++i) cout << id2[i] << " ";
//	cout << "Qwq" << endl;
	for (int qwq = 1; qwq <= tot1; ++qwq)
	{
		int i = id1[qwq];
		ins1(i, l[i]);
	}
	for (int i = 0; i <= tot; ++i) if(Exit[i].size())
	{
		stable_sort(Exit[i].begin(), Exit[i].end(), cmp);
		for (int j = 0; j < Exit[i].size(); ++j)
		{
			int k = Exit[i][j];
			int now = get1(k, r[k], len[k] - 1);
			Real[i][now]++;
			tar[i][now] = k;
			int last = 0;
			for (int l = r[k]; l < len[k]; ++l)
			{
				bucket[i][get1(k, r[k], l)] = true;
				if(Real[i].count(get1(k, r[k], l))) belong[k] += Real[i][get1(k, r[k], l)], last = tar[i][get1(k, r[k], l)];
				else if(l < len[k] - 1) tar[i][get1(k, r[k], l)] = last;
			}
		}
	}
	for (int qwq = 1; qwq <= tot2; ++qwq)
	{
		int i = id2[qwq];
		int now = 0;
		for (int k = ll[i]; k >= 0; --k)
		{
			int x = s3[i][k] - 'a';
			if(!trie[now][x]) break;
			now = trie[now][x];
			if(!Exit[now].size()) continue;
			int l = rr[i], r = Len[i] - 1, mid, ans = -1;
			while(l <= r)
			{
				mid = (l + r) >> 1;
				if(bucket[now].count(get3(i, rr[i], mid))) l = mid + 1, ans = mid;
				else r = mid - 1;
			}
			if(ans == -1) continue;
			::ans[i] += belong[tar[now][get3(i, rr[i], ans)]];
		}
	}
	for (int i = 0; i <= tot; ++i)
	{
		Exit[i].clear();
		memset(trie[i], 0, sizeof(trie[i]));
		bucket[i].clear();
		Real[i].clear();
		tar[i].clear();
		belong[i] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	p[0] = 1;
	for (int i = 1; i <= 5e6; ++i) p[i] = p[i - 1] * 13331ll % mod;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s1[i] >> s2[i];
		len[i] = s1[i].size();
		Has1[i].resize(len[i]), Has2[i].resize(len[i]);
		Has1[i][0] = s1[i][0], Has2[i][0] = s2[i][0]; 
		for (int j = 1; j < len[i]; ++j)
		{
			Has1[i][j] = (Has1[i][j - 1] * 13331ll + s1[i][j]) % mod;
			Has2[i][j] = (Has2[i][j - 1] * 13331ll + s2[i][j]) % mod;
		}
		int L = -1, R = 0;
		for (int j = 0; j < len[i]; ++j)
		{
			if(s1[i][j] != s2[i][j])
			{
				R = j;
				if(L == -1) L = j;
			}
		}
		l[i] = L, r[i] = R;
		arr[++num].id = i, arr[num].flg = 0;
		if(L != -1) arr[num].val1 = get1(i, L, R), arr[num].val2 = get2(i, L, R);
	}
	for (int i = 1; i <= q; ++i)
	{
		cin >> s3[i] >> s4[i];
		Len[i] = s3[i].size();
		Has3[i].resize(Len[i]), Has4[i].resize(Len[i]);
		Has3[i][0] = s3[i][0], Has4[i][0] = s4[i][0]; 
		for (int j = 1; j < Len[i]; ++j)
		{
			Has3[i][j] = (Has3[i][j - 1] * 13331ll + s3[i][j]) % mod;
			Has4[i][j] = (Has4[i][j - 1] * 13331ll + s4[i][j]) % mod;
		}
		int L = -1, R = 0;
		for (int j = 0; j < Len[i]; ++j)
		{
			if(s3[i][j] != s4[i][j])
			{
				R = j;
				if(L == -1) L = j;
			}
		}
		ll[i] = L, rr[i] = R;
		arr[++num].id = i, arr[num].flg = true;
		if(L != -1) arr[num].val1 = get3(i, L, R), arr[num].val2 = get4(i, L, R);
	}
	stable_sort(arr + 1, arr + num + 1);
	for (int i = 1; i <= num; ++i)
	{
		if(arr[i].val1 != arr[i - 1].val1 || arr[i].val2 != arr[i - 1].val2)
		{
			solve();
			tot1 = 0, tot2 = 0;
		}
		if(arr[i].flg) id2[++tot2] = arr[i].id;
		else id1[++tot1] = arr[i].id;
	}
	solve();
	for (int i = 1; i <= q; ++i) cout << ans[i] << endl;
	return 0;
}

