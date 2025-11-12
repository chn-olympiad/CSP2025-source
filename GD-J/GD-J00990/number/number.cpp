#include <bits/stdc++.h> 
using namespace std;

string s;
priority_queue<int> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	int l = s.length();
	for(int i = 0;i < l;i++)
		if(s[i] >= '0' && s[i] <= '9')
			q.push(s[i] - '0');	

	while(!q.empty())
	{
		cout << q.top();
		q.pop();
	}
	return 0;
} 
