#include<bits/stdc++.h>
using namespace std;
char s[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x>=1)
		{
			ans++;
		}
	}
	if(ans>=m)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
