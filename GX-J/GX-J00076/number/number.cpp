#include<bits/stdc++.h>
using namespace std;
int i;
string s;
long long a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int y=s.length();
	for(i=0;i<y;i++)
	{
		if(0<=int(s[i]-'0')&&int(s[i]-'0')<=9)
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
