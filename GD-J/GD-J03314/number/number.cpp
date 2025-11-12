#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6+5;
string s;
int a[N],cnt;

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	memset(a,-1,sizeof(a));
	for (int i = 0;i < s.size();i++)
		if (isdigit(s[i])) a[++cnt] = s[i] - '0';
	sort(a+1,a+cnt+1);
	for (int i = cnt;i >= 1;i--) cout << a[i];
	cout << endl;
	
	return 0;
}
