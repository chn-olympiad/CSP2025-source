#include <bits/stdc++.h>
using namespace std;
int a[15];
string b;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	int sum=0;
	for(int i=9;i>=0;i--)
	{
		while(a[i]>0)
		{
			b+='0'+i;
			a[i]--;
		}
	}
	cout<<b;
	return 0;
}
