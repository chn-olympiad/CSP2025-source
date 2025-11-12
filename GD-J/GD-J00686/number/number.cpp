#include<bits/stdc++.h>
using namespace std;

string s;
long long t[20];

int main()
{
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		char c = s[i];
		if(c>='0' && c<='9')
		{
			t[c-'0'+0]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(t[i]--)
		{
			cout<<i;
		}
	}
	return 0;
}
