#include <iostream>
#include <cstdio>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;
int n, q;
string s1[N], s2[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i ++)
	{
		cin >> s1[i] >> s2[i];
	}
	while(q--)
	{
		string x, y;
		cin >> x >> y;
		string xx = x;
		int ans = 0;
		for(int i = 1;i <= n;i ++)
		{
			if(xx.find(s1[i]) != -1)
			{
				xx.replace(xx.find(s1[i]), s1[i].size(), s2[i]);
				if(xx == y) ans ++;
			}
			xx = x;
		}
		cout << ans << endl;
	}
	return 0;
}

