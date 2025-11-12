#include<bits/stdc++.h>
using namespace std;

string s;
priority_queue<int> pq;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cd=s.size();
	for(int i=0;i<cd;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int x=s[i]-'0';
			pq.push(x);
		}
	}
	while(!pq.empty())
	{
		int t=pq.top();
		printf("%d",t);
		//cout<<t;
		pq.pop();
	}
	return 0;
}
