#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int a[1000005];
queue <int>q;
string s;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			q.push(s[i]-'0');
		}
		
	}
	int cnt=0;
	while(!q.empty())
	{
		a[++cnt]=q.front();
		q.pop();
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)cout<<a[i];
	return 0;
}
