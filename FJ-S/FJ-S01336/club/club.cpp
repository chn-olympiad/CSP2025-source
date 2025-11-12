#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,f[N][4],Max,v[4];
int nn[N];
void dfs(int num,int qw)
{
	memset(v,0,sizeof(v));
	if(num>n)
	{
		Max=max(Max,qw);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(nn[i]+1<=n/2)
		{
			nn[i]++;
			dfs(num+1,qw+f[num][i]);
			nn[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		Max=0xcfffffff;
		memset(nn,0,sizeof(nn));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&f[i][1],&f[i][2],&f[i][3]);
		dfs(1,0);
		cout<<Max<<"\n";
	}
	return 0;
}






