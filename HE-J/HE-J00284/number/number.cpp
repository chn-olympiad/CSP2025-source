#include<bits/stdc++.h>
using namespace std;
char s[1000010];
char a[1000010];
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long t=0;
	long long b=strlen(s);
	for(int i=0;i<b;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			t++;
			a[t]=s[i];
		}
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
