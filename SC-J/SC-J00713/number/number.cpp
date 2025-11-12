#include<bits/stdc++.h>
using namespace std;

int cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[100000];
	int num=0;
	int a[1005];
	cin>>s;
	int	n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[i]=int(s[i]-'0');
			num++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<num;i++)
	{
		cout<<a[i];
	}
	return 0;
}