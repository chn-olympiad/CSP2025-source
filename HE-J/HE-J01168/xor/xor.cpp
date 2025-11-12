#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10;
int n;
int ans = -1 * INT_MAX;
ll p, a[N];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> p;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	
	for (int k = 1; k <= n; ++k)
	{
		int num = 0;
		int l = k, r = l + 1;
		int pos = a[l];
		while (r <= n)
		{
//			cout << l << ' ' << r << endl;
			if (a[l] == p)
			{
				num++;
//				cout  << "num++ : " << l << ' ' << r << endl;
				l++, r++;
				pos = a[l];
				
			}
			else
			{
				pos = pos ^ a[r]; 
				if (pos == p) 
				{
					num++;
					l = r + 1;
					r = l + 1;
					pos = a[l];
//					cout  << "num++ : " << l << ' ' << r << endl;
				}
				else
				{
					r++;
				}
			}
//			cout << "pos: " << pos << endl;
		}
		ans = max(ans, num);
	}
	
//	if (a[n] == p) ans++;
	cout << ans;
	
	return 0;
}
