#include<bits/stdc++.h>
using namespace std;
priority_queue<char> q;
string s;
long long n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			q.push(s[i]);
		}
	}
	while(!q.empty())
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
}
