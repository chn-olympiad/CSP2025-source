#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read()
{
	char ch;
	ll s=0,f=1;
	ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		
		s=s*10+(ch-'0');
		ch=getchar();
	}
	return s*f;
}
string s;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<int(sizeof(s));i++)
	{
		char ch=s[i];
		if ('0'<=ch&&ch<='9')
		a[ch-'0']++;
	}
	for (int i=9;i>=0;i--)
	for (int j=a[i];j>0;j--)
	printf("%d",i);
	return 0;
}
