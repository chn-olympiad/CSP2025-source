#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5 , N1 = 131;
signed n , q;
short cnt[N];
string a , b;
map <pair <unsigned int , unsigned int> , vector <signed> > S1 , S3;
unordered_map <unsigned int , vector <signed> > S2;
vector <signed > s;
signed main ()
{
	freopen ("replace.in" , "r" , stdin);
	freopen ("replace.out" , "w" , stdout);
	ios::sync_with_stdio (0);
	cin.tie (0) , cout.tie (0);
	cin >> n >> q;
	while (n --)
	{
		cin >> a >> b;
		signed sz = a.size () , l = -1 , r = 0;
		for (signed j = 0;j < sz;j ++) if (a[j] != b[j])
		{
			if (l == -1) l = j;
			r = j;
		}
		unsigned int hs = 0 , Hs;
		for (signed j = l;j <= r;j ++) hs = hs * N1 + a[j] , hs = hs * N1 + b[j];
		S2[hs].push_back (n);
		Hs = hs;
		hs = 0;
		for (signed j = l - 1;j >= 0;j --) hs = hs * N1 + a[j];
		S1[{Hs , hs}].push_back (n);
		hs = 0;
		for (signed j = r + 1;j < sz;j ++) hs = hs * N1 + a[j];
		S3[{Hs , hs}].push_back (n);
	}
	while (q --)
	{
		cin >> a >> b;
		if (a.size () != b.size ())
		{
			cout << "0\n";
			continue;
		}
		signed sz = a.size () , l = -1 , r = 0;
		for (signed j = 0;j < sz;j ++) if (a[j] != b[j])
		{
			if (l == -1) l = j;
			r = j;
		}
		unsigned int hs = 0 , Hs;
		signed ans = 0;
		for (signed j = l;j <= r;j ++) hs = hs * N1 + a[j] , hs = hs * N1 + b[j];
		Hs = hs;
		s = S2[hs];
		for (signed id : s) cnt[id] = 0;
		hs = 0;
		s = S1[{Hs , hs}];
		for (signed id : s) cnt[id] ++;
		for (signed j = l - 1;j >= 0;j --)
		{
			hs = hs * N1 + a[j];
			s = S1[{Hs , hs}];
			for (signed id : s) cnt[id] ++;
		}
		hs = 0;
		s = S3[{Hs , hs}];
		for (signed id : s) cnt[id] ++;
		for (signed j = r + 1;j < sz;j ++)
		{
			hs = hs * N1 + a[j];
			s = S3[{Hs , hs}];
			for (int id : s) cnt[id] ++;
		}
		s = S2[Hs];
		for (signed id : s) ans += (cnt[id] == 2);
		cout << ans << '\n';
	}
	return 0;
}
