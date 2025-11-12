#include<bits/stdc++.h>
using namespace std;
int len,a[1000005],t;
char s[1000005];
bool cmp(int a1,int b1)
{
	if(a1>b1) return true;
	else return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++t]=s[i]-'0';
		}
	}
	sort(a+1,a+t+1,cmp);
	if(a[1]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=t;i++)
	{
		cout<<a[i];
	}
	return 0;
}
