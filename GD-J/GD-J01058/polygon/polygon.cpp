#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;

int n;
int a[5005] = {};
int lsta[5005] = {};
int ans[5005] = {};

bool cmp(int x, int y)
{
	return x > y;
}

int lstt(int staa, int pos, bool if_c)
{
	if(lsta[pos] <= a[staa]) return 0;
	else if(lstt(staa, pos + 1,true) == 0 && if_c == true && lsta[pos] > staa)
		return 1;
	else return lstt(staa, pos - 1, true) + lstt(staa, pos - 1, false);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	if(n == 3)
	{
		if(a[1] < a[2] + a[3]) cout << "1" << endl;
		else cout << "0" << endl;
		return 0;
	}
	for(int i = n; i >= 1; i--)
	{
		lsta[i] = lsta[i + 1] + a[i];
	}
	for(int i = 1; i < n - 1; i++)
	{
		ans[i] = lstt(i, i + 1, true) + lstt(i, i - 1, false);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		cnt += ans[i];
	}
	cout << cnt;
	return 0;
}
