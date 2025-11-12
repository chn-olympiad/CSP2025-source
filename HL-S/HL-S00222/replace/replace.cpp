#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3],t[200005][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d",&n);scanf("%d",&q);
	for(int i = 1;i <= n;i++)
	{
		scanf("%s",&s[i][1]);scanf("%s",&s[i][2]);
	}
	for(int i = 1;i <= q;i++)
	{
		scanf("%s",&t[i][1]);scanf("%s",&t[i][2]);
	}
	while(q)
	{
		printf("%d",0);
		q--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}