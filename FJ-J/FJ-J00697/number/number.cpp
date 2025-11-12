#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
const int maxn=1e6+5;
int a[maxn]={};
bool b[maxn]={};
bool cmp(int x,int y)
{
	return x>y;
}
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long len=s.length();
	for(long long i=0;i<len;i++)
	{
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			a[i]=s[i]-'0';
			b[i]=1;
		}	
	}
	string ans="";
	for(long long i=0;i<len;i++)
	{
		if(b[i]==1)
		{
			ans+=a[i]+'0';
		}
	}
	long long len1=ans.length();
	int c[len1]={0};
	for(long long i=0;i<len1;i++)
	{
		c[i]=ans[i]-'0';
	}
	sort(c,c+len1,cmp);
	for(long long i=0;i<len1;i++)
	{
		cout<<c[i];
	}
	return 0;
}
