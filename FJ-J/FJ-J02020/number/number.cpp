#include<bits/stdc++.h>
using namespace std;
string s;
int t[15];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
			t[s[i]-'0']++;
	}
	int flag=0;
	for(int i=9;i>=1;i--)
	{
		while(t[i])
		{
			t[i]--;
			flag=1;
			printf("%d",i);
		}
	}
	if(flag)
	{
		while(t[0])
		{
			t[0]--;
			printf("%d",0);
		}
	}
	else
		printf("%d",0);
	return 0;
}
