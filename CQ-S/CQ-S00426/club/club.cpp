#include<bits/stdc++.h>
using namespace std;
namespace IO {
	constexpr int bufsize = 230005;
	char buf[bufsize], *f1, *f2;
	char gtchar() {return f1 == f2 && (f1 = buf + fread(f2 = buf, 1, bufsize, stdin)) == buf? EOF: *f2++;}
	template<typename t> void read(t &ret)
	{
		int f = ret = 0;
		char ch = gtchar();
		while(!isdigit(ch)) f = ch == '-', ch = gtchar();
		while(isdigit(ch)) ret = ret * 10 + (ch ^ 48), ch = gtchar();
		if(f) ret = -ret;
	}
	template<typename t, typename ...T> void read(t &a, T &...b) {read(a), read(b...);}
}using IO::read;
constexpr int maxn = 100005;
int T, n, sum;
struct node {
	int a, b, c;
}s[maxn];
multiset<int> mx, mn;
void clear() {sum = 0, mx.clear(), mn.clear();}
void insert(int val)
{
	if(val < 0) return;
	// printf("insert %d\n", val);
	mn.insert(val);
}
int query(int rank)//rank --
{
	while(mx.size() < rank && mn.size()) mx.insert(*mn.rbegin()), sum += *mn.rbegin(), mn.erase(prev(mn.end()));
	while(mx.size() > rank) mn.insert(*mx.begin()), sum -= *mx.begin(), mx.erase(mx.begin());
	return sum;
}
void erase(int val)
{
	if(val < 0) return;
	// printf("erase %d\n", val);
	if(mx.count(val)) mx.erase(mx.find(val)), sum -= val;
	else mn.erase(mn.find(val));
}
void solve()
{
	clear();
	read(n);
	for(int i = 1; i <= n; ++i) read(s[i].a, s[i].b, s[i].c);
	// printf("n:%d %d\n", n, T);
	sort(s + 1, s + 1 + n, [](node a, node b) {return a.a - a.b > b.a - b.b;});
	int ans = 0, tot = 0, delta = 0, mid = n >> 1;
	priority_queue<int> q;
	for(int i = 1; i <= mid; ++i) tot += s[i].a, insert(s[i].c - s[i].a);
	for(int i = mid + 1; i <= n; ++i) tot += s[i].b, insert(s[i].c - s[i].b), q.push(s[i].c - s[i].b);
	ans = tot;
	// printf("ss%d\n", mn.size() + mx.size());
	for(int i = mid; i >= 0; i--)
	{
		int val = tot + delta + query(i);
		// printf("%d:%d %d %d\n", i, val, tot + delta, *mx.begin());
		ans = max(ans, val);
		if(i)
		{
			erase(s[i].c - s[i].a);
			insert(s[i].c - s[i].b);
			tot += s[i].b - s[i].a;
			q.push(s[i].c - s[i].b);
			erase(q.top()), delta += q.top();
			// printf("top:%d %d\n", q.top(), mn.size() + mx.size());
			q.pop();
		}
	}
	clear();;
	while(q.size()) q.pop();
	tot = delta = 0;
	for(int i = 1; i <= mid; ++i) tot += s[i].a, insert(s[i].c - s[i].a), q.push(s[i].c - s[i].a);
	for(int i = mid + 1; i <= n; ++i) tot += s[i].b, insert(s[i].c - s[i].b);
	// puts("fffff");
	for(int i = mid + 1; i <= n; ++i)
	{
		erase(s[i].c - s[i].b);
		insert(s[i].c - s[i].a);
		tot += s[i].a - s[i].b;
		q.push(s[i].c - s[i].a);
		erase(q.top()), delta += q.top();
		q.pop();
		int val = tot + delta + query(n - i);
		ans = max(ans, val);
		// printf("%d:%d\n", i, val);
	}
	printf("%d\n", ans);
}
int main()
{
	// freopen("./club/club5.in", "r", stdin);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	read(T);
	while(T--) solve();
	return 0;
}