#include <bits/stdc++.h>
using namespace std;
string s;
int len,t[11];
bool f;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			t[s[i]-'0']++;
			if(s[i]!='0')f=true;
		}
	}
	if(f)
	{
		for(int i=9;i>=0;i--)
		{
			for(int j=1;j<=t[i];j++)cout<<i;
		}
	}
	else cout<<0;
	return 0;
}