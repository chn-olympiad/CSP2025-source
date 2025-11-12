#include<bits/stdc++.h>
using namespace std;
string s;
int t=0;
int a[10000500];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++t]=s[i]-'0';
		}
	}
	for(int i=1;i<=t;i++)
	{
		for(int i=1;i<t;i++)
		{
			if(a[i]<a[i+1])
			swap(a[i],a[i+1]);
		}
	}
	for(int i=1;i<=t;i++)
	cout<<a[i];
	return 0;
}