#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s,x;
priority_queue<int> q;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++)
		if(s[i]>='0' && s[i]<='9') q.push((int)s[i]-'0');
	while(!q.empty())
	{
		x+=(char)(q.top()+'0');
		q.pop();
	}
	cout<<x;
	return 0;
}
