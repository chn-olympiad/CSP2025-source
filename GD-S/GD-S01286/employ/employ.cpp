#include<bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
vector<int> ord;
int s[N];
int n, m;
int c[N];
long long ans = 0;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) ord.push_back(i);
	char cf = getchar();
	for(int i = 1; i <= n; i++)
	{
		char ch = getchar();
		s[i] = ch - '0';
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	int t = -1;
	while(t != 0)
	{
		int stp = 0;
		int i = 0;
		int gt = 0;
		for(int v : ord)
		{
			i++;
			if(s[i] == 0)
			{
				stp++;
//				cout << stp << " ";
				continue;
			}
			if(stp >= c[v])
			{
				stp++;
//				cout << stp << " ";
				continue;
			}
//			cout << stp << " "; 
			gt++; 
		}
		if(gt >= m)
		{
//			for(int v : ord) cout << v << " ";
			ans++;
//			cout << endl;
		}
		ans %= mod;
		t = next_permutation(ord.begin(), ord.end());
	}
	cout << ans;
	return 0;
}
