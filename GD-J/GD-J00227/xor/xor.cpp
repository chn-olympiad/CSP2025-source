#include<bits/stdc++.h>
using namespace std;
int n,k,a[5005],w[5005][5005],ans;
int dfs(int x,int s)
{
	int ans=s;
	for(int i=x+1;i<=n;i++)
		for(int j=i;j<=n;j++)
			ans=max(ans,dfs(j,s+(w[i][j]==k)));
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		w[i][i]=a[i];
		for(int j=i+1;j<=n;j++)
			w[i][j]=w[i][j-1]^a[j];
	}
	printf("%d",dfs(0,0));
	return 0;
}
