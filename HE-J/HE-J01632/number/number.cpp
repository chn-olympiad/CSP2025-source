#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	memset(a,-1,sizeof(a));
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i]-'0';
		}
	}
	sort(a,a+1000001,cmp);
	for(int i=0;i<=1000001;i++)
	{
		if(a[i]!=-1)
		{
			cout<<a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
