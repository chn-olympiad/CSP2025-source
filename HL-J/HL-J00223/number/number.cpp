#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
string s;
int a[maxn];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s;
	int cnt = 0;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
			a[++cnt] = (int)(s[i] - '0');
	}
	sort(a+1,a+cnt+1,cmp);
	if(a[1] == 0)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= cnt;i++)
		cout << a[i];
	return 0;
}

