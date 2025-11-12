#include<bits/stdc++.h>
using namespace std;
int read()
{
	char ch=getchar();
	int x=0;
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
string getstr()
{
	char ch=getchar();
	string x="";
	while(ch<'a'||ch>'z')
		ch=getchar();
	while(ch>='a'&&ch<='z')
	{
		x+=ch;
		ch=getchar();
	}
	return x;
}
int n,T;
unordered_map<string,string>mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	T=read();
	for(int i=1;i<=n;i++)
	{
		string x=getstr(),y=getstr();
		mp[x]=y;
	}
	while(T--)
	{
		string x=getstr(),y=getstr();
		int ans=0,len=x.length();
		for(int i=0;i<len;i++)
			for(int t=i;t<len;t++)
			{
				string l=x.substr(0,i),m=x.substr(i,t-i+1),r=x.substr(t+1,len-t);
				if(l+mp[m]+r==y)
					ans++;
			}
		printf("%d\n",ans);
	}
	return 0;
}
