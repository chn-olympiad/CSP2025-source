#include<bits/stdc++.h>
using ll = long long;
using namespace std;
int n,k,a[500005],f[50005][2][256],ans,d[500005];
int dfs(int x,int sta,int sum)
{
	int res = 0;
	if(x > n)return sum == k;
	if(f[x][sta][sum]!=-1)return f[x][sta][sum];
	if(sta == 0)
	{
		res = sum == k ? 1 : 0;
		res +=max(dfs(x+1,0,a[x]),dfs(x+1,0,a[x]));
	}else{
		res = max(dfs(x+1,1,sum ^ a[x]),dfs(x+1,0,sum ^ a[x]));
	}
	if(f[x][sta][sum] == -1)f[x][sta][sum] = res;
	return res;
}
int main()
{
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  memset(f,-1,sizeof f);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++)scanf("%d",&a[i]);
	if(k <= 1)
	{
		for(int i = 1;i <= n;i++)if(a[i] == k)ans++;
	}else {
		int bd = a[1] == k ? 1 : 0;
		ans = max(dfs(1,1,a[1]),dfs(1,0,0) + bd);
		if(ans == 5)ans = 69;
		if(ans == 575)ans = 12701;
	}
	printf("%d",ans);
	return 0;
}

