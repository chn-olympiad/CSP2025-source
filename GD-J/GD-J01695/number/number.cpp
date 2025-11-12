#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	priority_queue<int>q;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int a=s[i]-'1'+1;
			q.push(a);
		}
	}
	while(!q.empty())
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
}
