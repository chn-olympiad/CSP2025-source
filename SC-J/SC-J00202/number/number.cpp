#include<iostream>
#include<string>
using namespace std;
string ans;
int flag[105];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	while (cin>>s)
	{
		if (s>='0' && s<='9')
		{
			flag[s-'0']++;
		}
	}
	for (int i=9;i>=0;i--)
	{
		while(flag[i]--)
		{
			char q=i+'0';
			cout<<q;
		}
	}
	cout<<ans;
	return 0;
 } 