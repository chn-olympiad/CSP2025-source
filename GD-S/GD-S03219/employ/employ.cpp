#include<bits/stdc++.h>
using namespace std;
int n,m,c[800],o,l;
char s[800];
bool vis[800];
void dfs(int dij,int sw)
{
	if(dij==n)
	{
		if(n-sw>=m)o++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==true)continue;
		vis[i]=true;
		if(sw>=c[i]||s[dij]=='0')dfs(dij+1,sw+1);
		else dfs(dij+1,sw);
		vis[i]=false;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf(" %c",&s[i]);
		if(s[i]=='1')l++;
	}
	for(int i=1;i<=n;i++)scanf(" %d",&c[i]);
	dfs(0,0);
	if(l<m)
	{
		printf("0");
		return 0;
	}
	if(l==m)
	{
		printf("1");
		return 0;
	}
	printf("%d",o);
	return 0;
 } 
