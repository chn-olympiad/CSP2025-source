#include<bits/stdc++.h>
using namespace std;
long long t[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long i,j;
	cin>>s;
	for(i=0;i<s.size();i++)
	{
		if(s[i]<='9' and s[i]>='0')
			t[s[i]-'0']++;
	}
	for(i=9;i>=0;i--)
	{
		if(t[i]!=0)
		{
			for(j=1;j<=t[i];j++)
				cout<<i;
		}
	}
	return 0;
}
