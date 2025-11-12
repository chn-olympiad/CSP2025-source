#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin)
	freopen("number.out","w",stdout)
	char s[1000000];
	int a[10],num;
	memset(a,0,sizeof(a));
	memset(s,'*',sizeof(s));
	cin>>s;
	num=strlen(s);
	for(int i=0;i<num;i++)
		if(s[i]-'0'==0||s[i]-'0'==1||s[i]-'0'==2||s[i]-'0'==3||s[i]-'0'==4||s[i]-'0'==5||s[i]-'0'==6||s[i]-'0'==7||s[i]-'0'==8||s[i]-'0'==9)
			a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++)
			cout<<i;
	return 0;
}
