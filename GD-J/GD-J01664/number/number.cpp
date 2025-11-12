#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
priority_queue<int> q;
int cnt;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			q.push(s[i]-48);
			cnt++;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
 } 
