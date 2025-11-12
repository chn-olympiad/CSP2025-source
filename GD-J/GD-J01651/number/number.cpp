#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
//typedef long long LL;
//const int MAXN = ;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	char c;
	priority_queue<int> ans;
	while (cin >> c)
		if (isdigit(c)) ans.push(c - '0');
	
	while (!ans.empty())
	{
		cout << ans.top();
		ans.pop();
	}
	cout << endl;
	
	return 0;
}
