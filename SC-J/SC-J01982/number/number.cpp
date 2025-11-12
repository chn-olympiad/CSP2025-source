#include<bits/stdc++.h>
using namespace std;
int a[10100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
	string s;
	int b;
	cin>>s;
	for(int i=1;i<=s.size();i++)
	{
		a[i]=s[i];
	}
	for(int i=1;i<=s.size();i++)
	{
		cout<<a[i];
	}
	return 0;
} 