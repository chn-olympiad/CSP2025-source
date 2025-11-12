#include <bits/stdc++.h>
using namespace std;
char s[1000002];
int numsum[11]={0};

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int length1=strlen(s);
	for(int i=0;i<=length1;i++)
	{
		if(s[i]>='0'&&s[i]<='9') numsum[(int)s[i]-48]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=numsum[i];j++) cout<<i;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
