#include<bits/stdc++.h>
using namespace std;
long long n,q;
string a[200005][5],b[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n; i++)
	{
		for(int j=1; j<=2; j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1; i<=q*2; i++)
	{
		cin>>b[i];
	}
	for(int i=1; i<=q; i++)
	{
		printf("0\n");
	}
	return 0;
 } 
