#include <bits/stdc++.h>
using namespace std;
int ton[11];
bool fla=false;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			ton[ s[i]-'0' ]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<ton[i];j++)
		{
			if(i!=0)
				fla=true;
			if(i==0 && !fla)
			{
				cout<<0;
				break;
			}
			cout<<i;
		}
	}
	return 0;
}
