#include<bits/stdc++.h>
using namespace std;
int T,n;
long long a[100005][5];
long long ans;
void dfs(int x,int y,int z,int k,long long s)
{
	if(x==n+1) 
	{
		if(y<=n/2&&z<=n/2&&k<=n/2)
		{
			ans=max(ans,s);
		}
		return ;
	}
	if(y>n/2||z>n/2||k>n/2) return ;
	dfs(x+1,y+1,z,k,s+a[x][1]);
	dfs(x+1,y,z+1,k,s+a[x][2]);
	dfs(x+1,y,z,k+1,s+a[x][3]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);ans=-1;
		for(int i=1;i<=n;i++) scanf("%lld %lld %lld",&a[i][1],&a[i][2],&a[i][3]);
		dfs(1,0,0,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
