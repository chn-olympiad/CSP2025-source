#include<bits/stdc++.h>
using namespace std;
//#define int long long

const int N = 25;

int c[N], x[N];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	//ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, ans = 0;
	cin >> n >> m;
	string s;
	cin >> s;
	s = "&" + s;
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	
	for(int i = 1; i <= n; i++)
		x[i] = i;
	do{
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			int now = x[i];
			if(i - 1 - cnt < c[now] && s[i] == '1')
				cnt++;
		}
		if(cnt >= m)
			ans++;
	}while(next_permutation(x + 1, x + n + 1));
	cout << ans;
	
	return 0;
}

