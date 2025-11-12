#include <bits/stdc++.h>
using namespace std;
priority_queue <int,deque<int>,less<int>> q;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			q.push(s[i]-'0');
		}
	}
	while(q.size())
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
}
