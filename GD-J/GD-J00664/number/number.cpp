#include<bits/stdc++.h>
using namespace std;
int a[1000010],t;
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
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[t++]=s[i]-'0';
		}
	}
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++)
	{
		cout<<a[i];
	}
}
