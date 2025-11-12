#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			int temp=s[i]-'0';
			q.push(temp); 
		}
	}
	while(!q.empty())
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
} 