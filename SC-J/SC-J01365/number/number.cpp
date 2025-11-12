#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<=len-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i]==0)continue;
		while(a[i]--)
		cout<<i;
	}
	return 0;
}