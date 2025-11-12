#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length();
	int num[len+1];
	for (int i=0;i<len;i++)
	{
		num[i]=-1;
	}
	for (int i=0;i<len;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			num[i]=(s[i]-'0');
		}
	}
	sort(num,num+len);
	for (int i=len-1;i>=0;i--)
	{
		if(num[i]!=-1)
			cout<<num[i];
	}
	return 0;
}
