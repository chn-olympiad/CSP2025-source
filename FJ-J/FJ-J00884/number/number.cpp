#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int v[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=1,maxn=-1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			v[j]=s[i]-'0';
			maxn=max(maxn,v[j]);
			j++;
		}
	}
	sort(v+1,v+j+1,cmp);
	if(maxn==0)
	{
		cout<<0;
	}
	else
	{
		for(int i=1;i<j;i++)
		{
			cout<<v[i];
		}
	}
	return 0;
}
