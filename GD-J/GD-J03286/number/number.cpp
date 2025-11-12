#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];
int t=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[t]=(s[i]-'0');
			t++;
		}	
	}
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++)
	{
		cout<<a[i];
	}
	return 0;
}
