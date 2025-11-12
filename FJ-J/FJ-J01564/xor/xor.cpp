#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
map <pii, int> f;
set <pii> ans;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> f[{i, i}];
		if (f[{i, i}] == k) 
		{
			ans.insert({i, i});
			//cout << i << ' ' << i << endl;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n - i; ++j)
		{
			f[{j, j+i}] = f[{j, j+i-1}] ^ f[{j+i, j+i}];
			if (f[{j, j+i}] == k) 
			{
				ans.insert({j, j+i});
				//cout << j << ' ' << j+i << endl;
			}
		}
	}
	
	cout << ans.size();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
