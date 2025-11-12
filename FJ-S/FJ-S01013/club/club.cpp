#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int ans,n,t,a[N][4],b[4];
void dfs(int x,int cnt)
{
	if(x>n)
	{
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=3;i++)
		if(b[i]<n/2)
		{
			b[i]++;
			dfs(x+1,cnt+a[x][i]);
			b[i]--;
		}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}