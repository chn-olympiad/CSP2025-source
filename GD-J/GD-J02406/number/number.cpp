#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int t[15];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s; int slen=strlen(s);
	for(int i=0;i<slen;i++)
	{
		if(s[i]>='0'&&s[i]<='9') t[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(t[i])
		{
			cout<<i; t[i]--;
		}
	}
	return 0;
}
