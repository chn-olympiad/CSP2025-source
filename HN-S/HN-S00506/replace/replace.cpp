# include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n , q , cnt;
string tar , tmp , s[200010] , t[200010];
void solve()
{
	cin >> tmp >> tar;
	for(int i = 1 , pos ; i <= n ; i ++)
	{
		pos = tmp.find(s[i]);
		if(pos != -1) cnt += tmp.substr(0 , pos) + t[i] + tmp.substr(pos + (int)t[i].size()) == tar;
	}
	cout << cnt + (tmp == tar) << "\n" , cnt = 0;
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++) cin >> s[i] >> t[i]; 
	while(q --) solve();
	return 0;
}
