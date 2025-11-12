#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	priority_queue<char> pq;
	string s;
	cin>>s;
	int i;
	for(i=0;i<s.size();i++)
		if(s[i]>='0' && s[i]<='9') pq.push(s[i]);
	while(!pq.empty())
	{
		cout<<pq.top();
		pq.pop();
	}
	return 0;
}
