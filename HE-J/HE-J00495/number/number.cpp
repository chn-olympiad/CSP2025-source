#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q; 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
			q.push(s[i]-'0');
	}
	if(q.top()==0)
	{
		cout<<0;
		return 0;
	}
	while(!q.empty())
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
}
