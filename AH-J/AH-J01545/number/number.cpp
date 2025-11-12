#include<bits/stdc++.h>
using namespace std;
string s;
int sh[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i];i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			sh[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<sh[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
