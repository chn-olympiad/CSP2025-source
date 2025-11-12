#include<bits/stdc++.h>
using namespace std;

string a[200005], b[200005], c, d, t;
long long n, q, ans, l, r;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
	}
	for(int i = 1; i <= q; i++){
		cin >> c >> d;
		ans = 0;
		for(int j = 1; j <= n; j++)
		{
			l = c.find(a[j]);
			r = l + a[j].size();
			while(l >= 0 && l < (long long) c.size() && r >= 0 && r < (long long) c.size()){
				if(l >= 0 && l < (long long) c.size() && r >= 0 && r < (long long) c.size()){
					t = c.substr(0,l) + b[j] + c.substr(r,c.size());
					if(t == d)
						ans++;
				}
				l = c.find(a[j], l+1);
				r = l + a[j].size();
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
