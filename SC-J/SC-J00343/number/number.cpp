#include<bits/stdc++.h>
using namespace std;
string s;
long long a,b[15],c;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	a=s.size();
	
	for(int i=0;i<a;i++)
	{
		if('0'<=s[i] && '9'>=s[i])
		{
			c=s[i]-'0';
			b[c]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(b[i]!=0)
		{
			for(int j=1;j<=b[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
}