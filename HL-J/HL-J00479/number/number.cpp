#include <iostream>
#include <cstdio>
using namespace std;
string s;
int a[1000005];
int main()
{
	freopen("number4.in","r",stdin);
	freopen("number4.ans","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		char p=s[i];
		if(p>='0'&&p<='9')
		{
			a[p-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i])
		{
			cout<<i;
			a[i]--;
		}
	}
}