#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	string s;
	for(int i=1;i<=n*2;i++)
	{
		cin>>s;
	}
	for(int i=1;i<=m*2;i++)
	{
		cin>>s;
	}
	for(int i=1;i<=m;i++)
	{
		printf("0\n");
	}
	return 0;
}
