#include <bits/stdc++.h>
using namespace std;
#define ll long long
char a[1000005];
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);
	ll n=strlen(a);
	for (ll i=0;i<n;i++)
	{
		if (a[i]>='0' && a[i]<='9')
			num[a[i]-'0']++;
	}
	for (int i=9;i>=0;i--)
	{
		for (int j=1;j<=num[i];j++)
			printf("%d",i);
	}
	return 0;
	}

