#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int N = 5 * 1e5 + 1,M = 25 * 1e4 + 1;
int n,k,a[N],cnt,ans,f[M],a1,a2;
bool c;
vector <int> st[N];
struct ST
{
	int l = 0,r = 0,cnt = 0;
	vector <int> a;
}s[M];
bool cmp(ST x,ST y)
{
	if (x.l != y.l) return x.l < y.l;
	return x.r < y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j < i;j++) st[i].push_back(0); 
		cin >> a[i];
		if (a[i] == 1 && c == 0) a1++;
		else if (a[i] == 0 && c == 0) a2++;
		else if (a[i] != 0 && a[i] != 1) c = 1;
		st[i].push_back(a[i]);
		if (st[i][i] == k) 
		{
			s[++cnt].l = i;
			s[cnt].r = i;
		}
		for (int j = 1;j < i;j++)
		{
			st[j].push_back(st[j][i - 1] ^ a[i]);
			if (st[j][i] == k) 
			{
				s[++cnt].l = j;
				s[cnt].r = i;
			}
		}
	}
	if (c == 0)
	{
		if (k == 0)
		{
			cout << a2;
			return 0;
		}
		else if (k == 1)
		{
			cout << a1;
			return 0;
		}
	}
	sort(s + 1,s + cnt + 1,cmp);
	for (int i = 1;i <= cnt;i++)
	{
		for (int j = 1;j <= cnt;j++)
		{
			if (i == j) continue;
			if (s[j].l > s[i].r) break;
			if (s[j].l >= s[i].l && s[j].r <= s[i].r)
			{
				f[i] = -1;
				s[i].l = 0;
				s[i].r = 0;
				for (int m = 1;m <= s[i].cnt;m++)
				{
					f[s[i].a[m]]--;
				}
				break;
			}
			if ((s[j].l >= s[i].l && s[j].l <= s[i].r) || (s[i].r >= s[j].l && s[i].r <= s[j].r))
			{
				f[i]++;
				s[i].a.push_back(j);
				s[i].cnt++;
			}
		}
		if (f[i] == 0) 
		{
			ans++;
			s[i].l = 0;
			s[i].r = 0; 
		}
	}
	for (int i = 1;i <= n;i++)
	{
		bool b = 0;
		if (s[i].cnt == 0) continue;
		for (int j = 1;j <= s[i].cnt;j++)
		{
			if (f[j] = -1) continue;
			if (s[i].cnt > s[j].cnt)
			{
				f[i] = -1;
				s[i].l = 0;
				s[i].r = 0;
				for (int m = 1;m <= s[i].cnt;m++)
				{
					f[s[i].a[m]]--;
				}
				b = 1;
				break;
			}
		}
		if (b == 0) ans++;
	}
	cout << ans;
	return 0;
}
