#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pair;
const int N = 2e5 + 5;
string s1[N] , s2[N];
int n;
void solve()
{
	string s , ns;
	cin >> s >> ns;
	ll ans = 0;
	for(int i = 1;i <= n;i++)
	{
		int t = 0;
		while(s.find(s1[i] , t) != -1 and ns.find(s2[i] , t) != -1)
		{
			int x = s.find(s1[i] , t);
			int y = ns.find(s2[i] , t);
			if(x == y)
			{
				string ts = s;
				ts.replace(x , s1[i].size() , s2[i]);
				if(ts == ns) ans++;
			}
			t = max(x , y) + 1;
		}
	}
	cout << ans << endl;
	return;
}
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	int q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> s1[i] >> s2[i];
	while(q--)
	{
		solve();
	}
	return 0;
}

