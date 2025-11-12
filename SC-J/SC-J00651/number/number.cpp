#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string n;
	priority_queue<int> q;
	cin >> n;
	if (n.size() == 1)
	{
		cout << n;
		return 0;
	}
	for (auto i : n)
	{
		if (isdigit(i))
		{
			q.push(i - '0');
		}
	}
	while (!q.empty())
	{
		cout << q.top();
		q.pop();
	}
	
	return 0;
}