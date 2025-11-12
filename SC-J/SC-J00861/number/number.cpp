#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],t=1;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[t]=int(s[i]-='0');
			t++;
		}
	}
	t-=1;
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++)
	{
		cout<<a[i];
	}
	return 0;
}