#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int c[15],ans[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	int cnt=0;
	for(int i=0;i<len;i++)
	{
		int k=s[i]-'0';
		if(k>=0&&k<=9)
		{
			c[k]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=c[i];j++)
		{
			ans[cnt]=i;
			cnt++; 
		}
	}
	for(int i=0;i<cnt;i++)cout<<ans[i];
	return 0;
}
