#include<bits/stdc++.h>
using namespace std;
int n;string s;
priority_queue<int>q;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;n=s.size();s=" "+s;
	for(int i=1;i<=n;i++)
		if('0'<=s[i]&&s[i]<='9')
			q.push(s[i]-'0');
	for(;!q.empty();q.pop())
		cout<<q.top();
	return 0;
}
