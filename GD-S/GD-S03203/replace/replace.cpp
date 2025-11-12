#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read()
{
	ll ret = 0 ,f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') f = (ch == '-' ? -f : f) ,ch = getchar();
	while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0' ,ch = getchar();
	return ret * f;
}

int n ,q;
const int N = 2e5 + 10 ,L = 5e6 + 10;
const ll base = 2011 ,mod = 1e9 + 7;
ll pw[L];
string s[N] ,t[N] ,a ,b; int l[N];
ll hs[N] ,ht[N] ,ha[L] ,hb[L];

ll get_val(string s)
{
	ll ret = 0;
	for (auto i : s) ret = (ret * base + i) % mod;
	return ret;
}
ll get_hs(int l ,int r ,ll *hs)
{
	if (l > r) return 0;
	return (hs[r] - hs[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}

int main()
{
	freopen("replace.in" ,"r" ,stdin);
	freopen("replace.out" ,"w" ,stdout);
	n = read() ,q = read();
	
	pw[0] = 1;
	for (int i = 1;i < N;i++) pw[i] = pw[i - 1] * base % mod;
	
	for (int i = 1;i <= n;i++)
		cin >> s[i] >> t[i] ,hs[i] = get_val(s[i]) ,ht[i] = get_val(t[i]) ,l[i] = s[i].size();
	
	while (q--)
	{
		cin >> a >> b;
		int len = a.size();
		a = ' ' + a ,b = ' ' + b;
		
		for (int i = 1;i <= len;i++)
			ha[i] = (ha[i - 1] * base + a[i]) % mod ,
			hb[i] = (hb[i - 1] * base + b[i]) % mod;
		
		ll ans = 0;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j + l[i] - 1 <= len;j++)
				if (get_hs(1 ,j - 1 ,ha) == get_hs(1 ,j - 1 ,hb) && get_hs(j + l[i] ,len ,ha) == get_hs(j + l[i] ,len ,hb))
					ans += (hs[i] == get_hs(j ,j + l[i] - 1 ,ha) && ht[i] == get_hs(j ,j + l[i] - 1 ,hb));
		
		printf("%lld\n",ans);
	}
	
	return 0;
}

