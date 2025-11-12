//忘记kmp了，1e4被干掉了，15tps 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
ll n, q, ans;
string t1, t2;
pair<string, string> str[N];
void solve()
{
//	cout << q << '\n';
	ans = 0;
	for(int i = 1; i <= n; ++i)//枚举二元组 
	{
		string f = str[i].first, s = str[i].second;
		ll len = f.size(), tlen = t1.size();
		ll l, t;//指针
		if(tlen < len) continue;
		for(int j = 0; j < tlen; ++j)
		{
			//前段是否一样
			bool flag = true;
			for(int p = 0; p < j; ++p)
			{
				if(t1[p] != t2[p])
				{
					flag = false;
					break;
				}
			}
			if(!flag) break;
			l = 0;
			t = j;
//			cout << '!'<<i <<' ' << j<< ' ' << t1[t] << ' ' << f[l] << '\n';
			while(t1[t] == f[l] && l < len && t < tlen) 
			{
				if(t2[t] == s[l])
				{
					l++;
					t++;
				}
				else break;
//				cout << '?'<<i << ' ' << t1[t] << ' ' << f[l] << '\n';
			}
//			cout << l << '\n';
			if(l == len)
			{
				bool flag = true;
				for(int p = t; p < tlen; ++p)//后段是否一样 
				{
					if(t1[p] != t2[p])
					{
						flag = false;
						break;
					}
				}
				if(flag) ans++;
			}
		} 
	}
	cout << ans << '\n';
}
int main()
{
	freopen("replace3.in", "r", stdin);
	freopen("repalce.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
	{
		string s1, s2;
		cin >> s1 >> s2;
		str[i].first = s1;
		str[i].second = s2;
	}
	while(q--)
	{
		cin >> t1 >> t2;
		solve();
	}
	return 0;
}
