#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
int a[N],cnt = 0;
bool cmp(int x,int y)
{
	return x > y;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	char p;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			p = s[i];
			a[cnt++] = p-'0';
		}
	}
	sort(a,a+cnt,cmp);
	for(int i = 0;i < cnt;i++)
	{
		cout << a[i];
	}
	return 0;
}