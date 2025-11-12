#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<char> q;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>s;
	int n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9') q.push(s[i]);
	}
	while(!q.empty())
	{
		cout<<q.top();
		q.pop(); 
	}
	return 0;
}