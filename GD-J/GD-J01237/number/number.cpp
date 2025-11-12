#include<bits/stdc++.h>
using namespace std;
string s;
char ch;
int ls;
int mp[10];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ls=s.size();
	for(int i=0;i<=ls-1;i++)
	{
		ch=s[i];
		if(ch>='0'&&ch<='9')
		{
			mp[ch-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=mp[i];j++)
		{
			printf("%d",i);
		}
	}
	return 0;
}
