#include <bits/stdc++.h>
using namespace std;
#define N 1000005
char s[N];
priority_queue<long long> q;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long len;
	cin.getline(s,1000005);
	len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int t=s[i]-'0';
			q.push(t);
		}
	}
	while(!q.empty())
	{
		cout<<q.top();
		q.pop();
	}
	cout<<endl;
	
	return 0;
}
