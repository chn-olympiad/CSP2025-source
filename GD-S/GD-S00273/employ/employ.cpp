#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[505];
char ss[505];
int s[505],cnt=1,ans=0;
int ns[505];
bool flag[20];
void dfs(int u)
{
	if(u>n)
	{
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt<a[ns[i]]&&ss[i]=='1') sum++;
			else cnt++;
		}
		if(sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!flag[i])
		{
			ns[u]=i;
			flag[i]=1;
			dfs(u+1);
			flag[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",ss+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1);
	printf("%d",ans);
	return 0; 
 } 

