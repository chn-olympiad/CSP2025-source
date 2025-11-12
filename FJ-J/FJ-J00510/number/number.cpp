#include<bits/stdc++.h>
using namespace std;
int a[1111111],b;
string s;
int main()
{
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[int(s[i]-48)]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		b=a[i];
		if(b>0)
		{
			for(int j=1;j<=b;j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
} 
