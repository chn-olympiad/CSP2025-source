#include<bits/stdc++.h>
using namespace std;
int t[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j,len,b=0,n;
	string s1;
	cin>>s1;
	len=s1.length();
	for(i=0;i<len;i++)
	{
		if(s1[i]>='0'&&s1[i]<='9') t[s1[i]-'0']++;
	}
	for(i=9;i>=0;i--)
	{
		n=t[i];
		if(n>0&&i>0) b=1;
		if(b==0&&i==0)
		{
			cout<<0;return 0;
		}
		for(j=1;j<=n;j++)
		{
			printf("%d",i);
		}
	}
	return 0;
}
