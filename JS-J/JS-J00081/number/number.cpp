#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<int> q;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(auto i : s) if(isdigit(i)) q.push(i - '0');
	while(!q.empty())
	{
		cout << q.top();
		q.pop();
	}
	return 0;
}
