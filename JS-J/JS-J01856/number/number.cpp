#include <bits/stdc++.h>
using namespace std;
int a[1000005],cnt,l;
string s;
bool cmp (int a1,int b)
{
	return a1>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	s=" "+s;
	for (int i=1;i<=l;i++)
	{
		if ('0'<=s[i] and s[i]<='9')
		{
			cnt++;
			a[cnt]=((int)(s[i]-'0'));
			//cout<<a[cnt];
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for (int i=1;i<=cnt;i++)
		printf("%d",a[i]);//cout<<a[i];
	return 0;
}
