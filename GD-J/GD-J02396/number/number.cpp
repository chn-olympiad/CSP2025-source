#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
string s;
int b=0,a[100000];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	cin>>s;
	for (int i=0;i<s.length();i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			a[b]=s[i];
			b++;
		}
	}
	sort(a,a+b,cmp);
	for (int j=0;j<b;j++)
	{
		cout<<a[j];
	}
	return 0;
}
