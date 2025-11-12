#include<bits/stdc++.h>
using namespace std;

int w[1000006],top=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			top++;
			w[s[i]-'0']++;
		}
	}
	bool f=0;
	for(int i=9;i>0;i--)
	{
		
		for(int j=1;j<=w[i];j++)
		{
			f=1;
			putchar(i+'0');
		}	
	}
	if(f==0)
	{
		putchar('0');
	}
	else{
		for(int j=1;j<=w[0];j++)
		{
			putchar('0');
		}
	}
}