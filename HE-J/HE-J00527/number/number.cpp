#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[500000];
	int pos=1;
	for (int i=0;i<s.length();i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			a[pos]=s[i]-'0';
			pos++;
		}
	}
	pos--;
	sort(a+1,a+pos+1,cmp);
	for (int i=1;i<=pos;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
