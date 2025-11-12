#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;
priority_queue<int> q;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int p=s[i]-'0';
			q.push(p);
		}
	}
	while(!q.empty())
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
}
