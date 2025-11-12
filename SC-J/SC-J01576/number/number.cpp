#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[MAXN];
	cin>>s;
	int n,num[10]={};
	n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if('0'<=s[i] && s[i]<='9')
		{
			int p=(s[i]-'0');
			num[p]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(num[i]>0)
		{
			cout<<i;
			num[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 