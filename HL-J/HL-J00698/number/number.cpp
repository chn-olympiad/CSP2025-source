#include <bits/stdc++.h>
using namespace std;

priority_queue<int> q;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cnt = 0;
	int len = s.size();
	
	for(int i = 0;i < len;i++)
	{
		if(s[i]>='0' && s[i] <= '9')
		{
			q.push(s[i]-'0');
			cnt++;
		}
	}
	for(int i = 1;i <= cnt;i++)
	{
		int x = q.top();
		cout << x;
		q.pop();
	}
	return 0;
}