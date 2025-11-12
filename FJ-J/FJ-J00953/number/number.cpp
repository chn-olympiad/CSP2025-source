#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int f[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	int num=0;
	for(int i=0;i<n;i++)
	{
		if ('0'<=s[i]<='9')
		{
			f[s[i]-'0']++;
		}
	}
	for(int i=9;0<=i;i--)
	{
		while (f[i]--)
		{
			cout<<i;
		}
	}
	return 0;
}
