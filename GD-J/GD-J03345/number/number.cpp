#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
string s;
int a[1000015];
int cnt;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=" "+s;
	for(unsigned int i=1;i<=s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)cout<<a[i];
} 
