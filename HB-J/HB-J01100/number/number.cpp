#include<bits/stdc++.h>
using namespace std;
string s;
int book[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			book[s[i]-'0']++;
		}
	}
	for(int i=10;i>=0;i--)
	{
		while(book[i]>0)
		{
			cout<<i;
			book[i]--;
		}
	}
	return 0;
}
