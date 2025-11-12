#include<bits/stdc++.h>
using namespace std;
int st[10];
string s,s1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			st[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(st[i]!=0)
		{
			while(st[i])
			{
				st[i]--;
				s1+=char(i+'0');
			}
		}
	}
	cout<<s1;
	return 0;
} 
/*
	5
	*/
