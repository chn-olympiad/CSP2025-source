#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n,m,nnan[1000],human[1000],ans;
int a[1000],b[1000];//用过没，放哪里 
void dfs(int x)
{
	if(x>n)
	{
		int cnt=0,cnt1=0;
		//for(int i=1;i<=n;i++) cout<<b[i]<<" ";
		for(int i=1;i<=n;i++)
		{
		    if(cnt1>=human[b[i]]) 
			{
				cnt1++;
				continue;
			}
			if(nnan[i]==0) cnt++;
			else cnt1++;
		}
		if(cnt>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			b[x]=i;
			a[i]=1;
			dfs(x+1);
			a[i]=0;
			b[x]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%1d",&nnan[i]);
	for(int i=1;i<=n;i++) scanf("%d",&human[i]);
	dfs(1);
	printf("%d",ans%998244353);
	return 0;
}
