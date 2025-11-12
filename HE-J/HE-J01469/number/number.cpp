#include<bits/stdc++.h>
using namespace std;
string s;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lens = s.length();
	for(int i = 9;i>=0;i--)
	{
		for(int j = 0;j<lens;j++)
		{
			if(s[j]-'0' == i)
			{
				cout<<s[j]-'0';
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
