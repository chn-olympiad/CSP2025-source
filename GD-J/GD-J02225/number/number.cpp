#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	priority_queue<int> q;
	while(!q.empty()) q.pop();
	for (int i=0;i<len;i++)
	{
		if (isdigit(s[i])) q.push(s[i]-'0');
	}
	while(!q.empty())
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
}
