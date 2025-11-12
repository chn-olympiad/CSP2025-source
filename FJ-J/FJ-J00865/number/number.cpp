#include<bits/stdc++.h>
using namespace std;
string s,a;//49
long long b[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i = 0;i<s.size();i++)
	{
		if (s[i]>=48&&s[i]<=57) a += s[i];
	}
	for(int j = 0;j<a.size();j++)
	{
		b[j] = a[j]-48;
	}
	sort(b,b+a.size()+1);
	for(int k = a.size();k>=1;k--)
	{
		cout<<b[k];
	}
	return 0;
}

