#include<bits/stdc++.h>
#include<queue>
using namespace std;
string s;
priority_queue<long long,vector<long long>,less<long long> > q;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			q.push(s[i]-'0');
		}
	}
	while(!q.empty())
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
}
