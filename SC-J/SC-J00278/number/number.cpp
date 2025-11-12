#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000000];
	cin>>s;

	int len=strlen(s),n=0,a[len];
	for(int i=0;i<len;i++)
	{
			if(s[i]>='0'&&s[i]<='9')
			{
					a[n]=s[i]-'0';
					n++;
			}
}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
			if(a[i]>=0&&a[i]<=9)
			printf("%d",a[i]);
	}
	
	return 0;
}