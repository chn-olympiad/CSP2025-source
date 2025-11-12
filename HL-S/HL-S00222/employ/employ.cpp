#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],num = 1;
bool s[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d",&n);scanf("%d",&m);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i = 0;i < m;i++)
	{
		scanf("%d",&s[i]);
	}
	for(int i = 0;i < n;i++)
	{
		num *= n;
		n--;
	}
	printf("%d",num);
	fclose(stdin);
	fclose(stdout);
	return 0;
}