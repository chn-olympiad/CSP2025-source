#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 10;

string a;
int num[N], cnt;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int len = a.size();
	for(int i = 0; i < len; i ++ )
		if(a[i] >= '0'&& a[i] <= '9')
			num[++ cnt] = a[i] - '0';
	sort(num + 1, num + cnt + 1, cmp);
	if(num[1] == 0)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= cnt; i ++ )
		cout << num[i];
	return 0;
}
