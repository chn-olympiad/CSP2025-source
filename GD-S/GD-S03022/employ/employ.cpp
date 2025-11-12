#include<bits/stdc++.h>
using namespace std;
int s[505],c[505],n,m;
int p[505],bz[505],ans;
void dfs(int x,int lq)
{
	if(x>n) ans+=(lq>=m);
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(!bz[i])
			{
				bz[i]=1;
				if((x-1-lq)>=c[i]||s[x]==0) dfs(x+1,lq);
				else dfs(x+1,lq+1);
				bz[i]=0;
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%1d",&s[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs(1,0);
	printf("%d",ans);
}
