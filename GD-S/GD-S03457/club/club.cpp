#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pli;
void rdi(int& x)
{
	char c;
	while((c = getchar_unlocked()) > '9' || c < '0');
	x = c - '0';
	while((c = getchar_unlocked()) >= '0' && c <= '9')
	{
		x = x * 10 + c - '0';
	}
}
int n;
struct Node {
	int a1, a2, a3, dif2, dif3, ddif;
	void in()
	{
		rdi(a1); rdi(a2); rdi(a3);
		dif2 = a2 - a1;
		dif3 = a3 - a1;
		ddif = dif3 - dif2;
	}
} a[100005];
bool cmp(Node x, Node y)
{
	return x.ddif > y.ddif;
}
mt19937 RD(chrono::system_clock::now().time_since_epoch().count());
struct FHQ_Node {
	int l, r, val, sz;
	ll sum, pri;
	FHQ_Node() {l = r = val = sz = sum = 0; pri = -1e18;}
	FHQ_Node(ll v) {l = r = 0; val = sum = v; sz = 1; pri = RD();}
};
struct FHQ {
	vector<FHQ_Node> a = vector<FHQ_Node>(1);
	int sz = 0, rt = 0;
	void pushup(int x)
	{
		a[x].sz = a[a[x].l].sz + a[a[x].r].sz + 1;
		a[x].sum = a[a[x].l].sum + a[a[x].r].sum + a[x].val;
	}
	void split(int x, int v, int& L, int& R)
	{
		if(!x)
		{
			L = R = 0;
			return;
		}
		if(a[x].val < v)
		{
			split(a[x].r, v, a[L = x].r, R);
		}
		else
		{
			split(a[x].l, v, L, a[R = x].l);
		}
		pushup(x);
	}
	int merge(int L, int R)
	{
		if(!L || !R)
		{
			return L + R;
		}
		if(a[L].pri > a[R].pri)
		{
			a[L].r = merge(a[L].r, R);
			pushup(L);
			return L;
		}
		a[R].l = merge(L, a[R].l);
		pushup(R);
		return R;
	}
	void ins(int v)
	{
		int L, R;
		split(rt, v, L, R);
		a.push_back(FHQ_Node(v));
		sz++;
		rt = merge(L, merge(sz, R));
	}
	void del(int v)
	{
		int L, M, R;
		split(rt, v, L, M);
		split(M, v + 1, M, R);
		rt = merge(L, merge(a[M].l, merge(a[M].r, R)));
	}
	int kthmx(int x, int k)
	{
		if(k == a[a[x].r].sz + 1)
		{
			return a[x].val;
		}
		if(k <= a[a[x].r].sz)
		{
			return kthmx(a[x].r, k);
		}
		return kthmx(a[x].l, k - a[a[x].r].sz - 1);
	}
	pli gevsc(int v)
	{
		int L, R;
		split(rt, v, L, R);
		pli ret = make_pair(a[R].sum, a[R].sz);
		rt = merge(L, R);
		return ret;
	}
};
void solve()
{
	rdi(n);
	int sum1 = 0;
	for(int i=1;i<=n;i++)
	{
		a[i].in();
		sum1 += a[i].a1;
	}
	sort(a + 1, a + n + 1, cmp);
	int ans = -2e9;
	FHQ p3, s2, ng;
	p3.a.reserve(n + 1);
	s2.a.reserve(n + 1);
	ng.a.reserve(n + 1);
	for(int i=1;i<=n;i++)
	{
		s2.ins(a[i].dif2);
		if(a[i].dif2 < 0)
		{
			ng.ins(a[i].dif2);
		}
	}
	for(int i=0;i<=n;i++)
	{
		if(i)
		{
			p3.ins(a[i].dif3);
			if(a[i].dif3 < 0)
			{
				ng.ins(a[i].dif3);
			}
			s2.del(a[i].dif2);
			if(a[i].dif2 < 0)
			{
				ng.del(a[i].dif2);
			}
		}
		int chc = 0, ad = 0;
		if(i)
		{
			int k3;
			k3 = p3.kthmx(p3.rt, min(n / 2, i));
			if(k3 >= 0)
			{
				ad += p3.gevsc(k3).first;
				chc += min(n / 2, i);
			}
			else
			{
				pli g3 = p3.gevsc(0);
				ad += g3.first;
				chc += g3.second;
			}
		}
		if(i < n)
		{
			int k2;
			k2 = s2.kthmx(s2.rt, min(n / 2, n - i));
			if(k2 >= 0)
			{
				ad += s2.gevsc(k2).first;
				chc += min(n / 2, n - i);
			}
			else
			{
				pli g2 = s2.gevsc(0);
				ad += g2.first;
				chc += g2.second;
			}
		}
		if(chc < n / 2)
		{
			ad += ng.gevsc(ng.kthmx(ng.rt, n / 2 - chc)).first;
		}
		ans = max(ans, ad);
	}
	cout << ans + sum1 << '\n';
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ll tt;
	cin >> tt;
	while(tt--)
	{
		solve();
	}
	return 0;
}
