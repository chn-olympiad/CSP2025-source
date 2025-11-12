#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
int c=0;
bool comp(char a,char b)
{
	if(a>b) return true;
	return false;
}
int main()
{
	/*if(freopen("number1.in","r",stdin)==NULL)
	{
		perror("重定向错误");
		return 1;
	}
	if(freopen("number1.out","w",stdout)==NULL)
	{
		perror("重定向错误");
		return 1;
	}
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);*/
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[c]=s[i];
			c++;
		}
	}
	sort(a,a+c,comp);
	for(int i=0;i<c;i++)
	{
		cout<<a[i];
	}
	return 0;
}