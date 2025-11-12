#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],z[505],rs,ans,sum[505];
char s[505];
const int p=998244353;
void dfs(int k)
{
	if(k>n)
	{
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!z[i])
		{
			if(rs>=c[i])
			{
				rs++;
				z[i]=1;
				if(k-rs+sum[k+1]>=m)
					dfs(k+1);
				z[i]=0;
				rs--;
				continue; 
			}
			if(s[k]=='0')
				rs++;
			z[i]=1;
			if(k-rs+sum[k+1]>=m)
				dfs(k+1);
			z[i]=0;
			if(s[k]=='0')
				rs--;
		}
	}
}
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=n;i>=1;i--)
		sum[i]=sum[i+1]+(s[i]=='1');
	sort(c+1,c+1+n,cmp);
	dfs(1);
	printf("%d",ans);
	return 0;
}
