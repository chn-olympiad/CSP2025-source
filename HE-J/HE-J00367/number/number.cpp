#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
string s;
priority_queue<int>qq;
long long a[N]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int l1=s.size();
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			int k=s[i]-'0';
			qq.push(k);
		}
	}
	int l=qq.size();
	for(int i=1;i<=l;i++)
	{
		a[i]=qq.top();
		qq.pop();
	}
	for(int i=1;i<=l;i++)
	{
		cout<<a[i];
	}
	return 0;
}
