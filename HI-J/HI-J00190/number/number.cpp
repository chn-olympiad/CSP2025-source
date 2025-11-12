#include<bits/stdc++.h>
using namespace std;
string s;
int t[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]<='9' && s[i]>='0')
		{
			t[s[i]-'0']++;
		}
			
	}
	for(int i=9;i>=0;i--)
	{
		if(t[i]!=0)
		{
			for(int j=t[i];j>0;j--)
			{
				cout<<i;
			}
		}
	}
	return 0;
}
