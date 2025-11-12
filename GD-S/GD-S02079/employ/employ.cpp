#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<cmath>
using namespace std;
int n,m,x,w_ans,c[505],a[505],w_vis[505];
char s[506];
void w_dfs(int k)
{
	if(k>n)
	{
		x=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]!='1'||x>=c[a[i]])
				x++;
		}
		if(n-x>=m)
			w_ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!w_vis[i])
		{
			a[k]=i;
			w_vis[i]=1;
			w_dfs(k+1);
			w_vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d %s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	w_dfs(1);
	printf("%d",w_ans);
	return 0;
}
