# include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10, inf = 0x3f3f3f3f;
int a[N], s[N], cnt[N], mn[N], tot;
struct node
{
	int l, r;
} t[N];

int cmp(node a, node b)
{
	return a.r < b.r;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(mn, 0x3f, sizeof mn);
	int n, k; cin >> n >> k;
	for(int i = 1;i <= n;i ++ ) 
	{
		cin >> a[i]; s[i] = s[i - 1] ^ a[i];
	}
	for(int i = n;i >= 1;i -- )
	{
		if(i != n && cnt[k ^ s[i]]) 
		{
			t[ ++ tot] = (node){i + 1, mn[k ^ s[i]]};
		}
		if(a[i] == k)
		{
			t[ ++ tot] = (node){i, i};
		}
		cnt[s[i]] ++ , mn[s[i]] = min(mn[s[i]], i);
	}
	if(cnt[k])
	{
		t[ ++ tot] = (node){1, mn[k]};
	}
	
	sort(t + 1, t + tot + 1, cmp);
	int lst = 0, ans = 0;
	for(int i = 1;i <= tot;i ++ )
	{
		
		if(t[i].l > lst) ans ++ , lst = t[i].r;
	}
	cout << ans;
	return 0;
}