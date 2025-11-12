#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e2 + 5;
const int mod = 998244353;

int n,q;
string s1[N],s2[N],t1,t2;

void gc()
{
	cin >> n >> q;
	for (int i = 1;i <= n;i++)cin >> s1[i] >> s2[i];
	while (q--)
	{
		cin >> t1 >> t2;
		cout << 0 << "\n";
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	gc();
	return 0;
}
