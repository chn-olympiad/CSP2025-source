#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1;
	cin>>s1;
	char s2[10000001];
	for(int i=1;i<=s1.length();i++)
	  s2[i]=s1[i-1];
	char s[10000001];
	int c=1;
	for(int i=1;i<=s1.length();i++)
	  if(s2[i]>='0'&&s2[i]<='9')
	  	s[c++]=s2[i];
	int tong[10];
	for(int i=1;i<=c;i++)
	  tong[s[i]-'0']++;
	for(int i=9;i>=0;i--)
	  for(int j=1;j<=tong[i];j++)
	    cout<<i;
	return 0;
}
