#include<bits/stdc++.h>
using namespace std;
int a[1000001],j=0,n=0;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++j]=s[i]-'0';
			n++;
		}
	}
	sort(a+1,a+n+1,cmp);
	if(a[1]==0)
	{
		cout<<0;
		return 0;
	}
	for(int k=1;k<=n;k++)
	{
		cout<<a[k];
	}
	return 0;
}
