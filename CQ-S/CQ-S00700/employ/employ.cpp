#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
bool empl[505];
int pati[505];
int b[505];
bool vis[505];
int cnt1=0;
void dfs(int x)
{
	if(x==n+1)
	{
		int num=0;
		for(int i=1;i<=n;i++)
		{
//			printf("%d %d %d\n",pati[b[i]],empl[i],num);
			if(empl[i]==0||num>=pati[b[i]])
			{
				num++;
			}
		}
//		printf("\n");
//		printf("%d\n",num);
		if(num<=n-m)ans++;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		b[x]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		char c;
		scanf(" %c",&c);
		empl[i]=c-'0';
		cnt1+=empl[i];
	}
	if(cnt1<m)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)scanf("%d",&pati[i]);
	dfs(1);
	printf("%d",ans);
	return 0;
}

