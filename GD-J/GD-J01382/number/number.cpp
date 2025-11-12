#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000010];
bool cmp(int x,int y)
{
	return x > y;
}

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int n = 0;
	for(int i = 0;i < s.size();i++)
	{
		if('0' <= s[i]&&s[i]<='9')
		{
			n++;
			a[n] = s[i] - '0';
			
		}
	}
	sort(a+1,a+n+1,cmp);
	if(a[1] == 0)
	{
		cout << 0;
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			cout << a[i];
		}
	}
	return 0;
 } 
