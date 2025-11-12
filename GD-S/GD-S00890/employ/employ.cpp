#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,c[505],id[505];
string s;
int ans;
const int mod = 998244353;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> s;
	for(int i = 0;i < n;i++) cin >> c[i];
	for(int i = 0;i < n;i++) id[i] = i;
	
	do
	{
		int cnt = 0,res = 0;
		for(int i = 0;i < n;i++)
		{
			if(cnt >= c[id[i]])
			{
				cnt++;
				continue;
			}
			if(s[i] == '0') cnt++;
			if(s[i] == '1') res++;
		}
		if(res >= m) ans = (ans + 1) % mod;
	}
	while(next_permutation(id,id + n));
	cout << ans;
	return 0;
} 
