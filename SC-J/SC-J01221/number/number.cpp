//普巴保佑我AC 
#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	priority_queue<int> q;
	for(char c:s)
		if(isdigit(c))
			q.push((c-'0'));
	while(!q.empty())
	{
		cout<<q.top();
		q.pop();
	}	
	return 0;
}