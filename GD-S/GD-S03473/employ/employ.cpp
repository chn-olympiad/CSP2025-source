#include<bits/stdc++.h>
using namespace std;
int n,m,c[15],zt[15],ans;
bool vis[15];
char s[15];
void dfs(int k)
{
	if(k>n)
	{
		int dq=0,num=0;
		for(int i=1;i<=n;i++)
		{
			if(dq<c[zt[i]]&&s[i]=='1') num++;
			else dq++;
		}
		ans+=num>=m;
		return;
	}
	for(int i=1;i<=n;i++) 
		if(!vis[i])
		{
			vis[i]=1;
			zt[k]=i;
			dfs(k+1);
			vis[i]=0; 
		}
 } 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs(1);
	printf("%d",ans);
	return 0;
}

