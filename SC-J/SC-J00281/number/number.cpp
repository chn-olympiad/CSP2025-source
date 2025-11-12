#include<bits/stdc++.h>
using namespace std;
string s;
long long len,k;
priority_queue<long long> q;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			k=int(s[i]-'0');
			q.push(k);
		} 
	}
	while(!q.empty())
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
 } 