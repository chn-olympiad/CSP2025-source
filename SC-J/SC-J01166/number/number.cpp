#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
priority_queue<int> q;
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lens=s.size();
	for(int i=0;i<lens;i++)
	{
		if(s[i]>='0'&&s[i]<='9') q.push(s[i]-'0');
	}
	while(!q.empty())
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
}
//100+0+0+0=100