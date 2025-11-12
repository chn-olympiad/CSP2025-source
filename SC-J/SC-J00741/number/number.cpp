#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
string s;
int a[10],id;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	cin>>s;
//	for(int i=0;i<s.length();i++)
//	{
//		if(s[i]>='0'&&s[i]<='9')
//		{
//			a[s[i]-'0']++;
//		}
//	}
	char c;
	while(cin>>c)
	{
		if(c>='0'&&c<='9')
		{
			a[c-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}