#include<bits/stdc++.h>
using namespace std;
string s;
int m,t[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();++i)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			m=s[i];
			t[m-48]++;
		}
	}
	for(int i=10;i>=0;--i)
	{
		for(int j=1;j<=t[i];++j)
		{
			cout<<i;
		}
	}
	return 0;
}
