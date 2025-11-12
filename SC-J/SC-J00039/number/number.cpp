#include<bits/stdc++.h>
using namespace std;
void read(long long &n)
{
	n=0;
	char c=getchar();
	while(c>'9' or c<'0')c=getchar();
	while(c<='9' and c>='0')
	{
		n=n*10+c-'0';
		c=getchar();
	}
}
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<int(s.size());i++)
	{
		if('0'<=s[i] and s[i]<='9')a[++cnt]=10-s[i]+'0';
	}
	sort(a+1,a+cnt+1);
	for(int i=1;i<=cnt;i++)
	{
		printf("%d",10-a[i]);
	}
	return 0;
}