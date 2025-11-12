#include<bits/stdc++.h>
using namespace std;
string s;
long long t[1000000];
int cmp(int a,int b)
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
			t[i]=s[i]-'0';
		}
		else
		{
			t[i]=-1;
		}
	}
	sort(t,t+s.size(),cmp);
	for(int i=0;i<s.size();i++)
	{
		if(t[i]>=0)
		{
			cout<<t[i];
		}
	}
	return 0;
}