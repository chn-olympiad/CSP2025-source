#include<bits/stdc++.h>
using namespace std;
#define sp " "
#define pb push_back
#define mp make_pair
#define f(s, i, x, y) for(s i = x; i <= y; i++)
typedef long long ll;
const int N = 2e5+5;
int n, q, a1[N], b1[N], ans;
string a[N], b[N], t1, t2;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	f(int, i, 1, n)
	{
		cin >> a[i] >> b[i];
		int j = 0;
		while(a[i][j] != 'b')
			j++;
		a1[i] = j;
		j = 0;
		while(b[i][j] != 'b')
			j++;
		b1[i] = j;
	}
	while(q--)
	{
		ans = 0;
		cin >> t1 >> t2;
		for(int i = 0; i < t1.size(); i++)
		{
			if(t1[i] == 'b')
			{
				for(int j = 1; j <= n; j++)
				{
					string beg = t1.substr(0, i+1);
					string ss = t1.substr(i-a1[j], a[j].size());
					string ed = t1.substr(i-a1[j]+a[j].size()+1, t1.size()-i-1-a[j].size());
					if(ss == a[j] && beg+ss+ed == t2) ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
