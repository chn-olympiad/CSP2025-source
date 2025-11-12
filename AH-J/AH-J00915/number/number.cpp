# include <bits/stdc++.h>
using namespace std;
int canuse[101];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(isdigit(s[i])) canuse[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		if(canuse[i])
		{
			for(int j=1;j<=canuse[i];j++)
			{
				printf("%d",i);
			}
		}
	}
	return 0;
}
