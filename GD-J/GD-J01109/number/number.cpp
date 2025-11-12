#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
string s;
string a;
int ans[N];
bool cmp(int x,int y)
{
	if (x!=y) return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> s;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			a+=s[i];
		}
	}
	for (int i=0;i<a.size();i++)
	{
		ans[i] = a[i]-'0';
	}
	int n = a.size();
	sort(ans,ans+n,cmp);
	for (int i=0;i<n;i++)
	{
		cout << ans[i];
	}
	return 0;
}
