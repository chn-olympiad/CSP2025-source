#include <bits/stdc++.h>
using namespace std;
priority_queue<char> g;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char k;
	while(cin >> k)
	{
		if(isdigit(k)) g.push(k);
	}
	while(g.size())
	{
		cout << char(g.top());
		g.pop();
	}
	return 0;
}