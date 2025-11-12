#include <bits/stdc++.h>
#define int long long
#define loop(a,b) for (int a = 1 ; a <= b ; ++a)
using namespace std;
int a[10];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	char ch;
	while (cin >> ch)
	{
		if (ch>='0'&&ch<='9') a[ch-'0']++;
	}
	for (int i = 9 ; i >= 0 ; --i)
	{
		loop(j,a[i]) cout << i; 
	}
	return 0;
}
