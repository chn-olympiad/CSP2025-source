#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	getline(cin,s);
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if('0'<=s[i] && s[i]<='9')
		{
			q.push(int(s[i]-'0'));//统计数字并入队
		}
	}
	while(!q.empty())
	{
		cout<<q.top();//用大根堆从大到小输出
		q.pop();
	}
	return 0;
}