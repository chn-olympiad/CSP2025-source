#include<bits/stdc++.h>
using namespace std;
bool com(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[1000005];
	int len=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0' or s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9')
		{
			a[len]=s[i];
			len++;
		}
	}
	sort(a,a+len,com);
	for(int i=0;i<len;i++)
	{
		cout<<a[i];
	}
	return 0;
}
