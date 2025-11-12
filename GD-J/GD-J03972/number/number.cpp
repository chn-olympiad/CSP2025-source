#include<bits/stdc++.h>
using namespace std;
#define ll long long
char c[1000005];
ll n,a[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c+1);
	n=strlen(c+1);
	for(int i=1;i<=n;i++)
	{
		if(c[i]>='0'&&c[i]<='9')
		{
			a[c[i]-'0']++;
		}
	}
	for(ll i=9;i>=0;i--)
	{
		for(ll j=1;j<=a[i];j++)
		{
			printf("%lld",i);
		}
	}
	return 0;
}
