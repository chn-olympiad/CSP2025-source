#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string s;
int tmp[1000005],tot=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			tmp[++tot]=s[i]-'0';
		}
	}
	sort(tmp+1,tmp+tot+1);
	for(int i=tot;i>=1;i--)
	{
		printf("%d",tmp[i]);
	}
	return 0;
}
