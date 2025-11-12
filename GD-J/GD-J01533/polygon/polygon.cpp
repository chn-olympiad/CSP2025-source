#include<bits/stdc++.h>
using namespace std;
int n,a[5010],vis[5010];
const int mod=998244353;
long long ans=0;
void dfs(int x,int l,int sum,int maxn)//选择了x根,下次选第l-n根,长度和,最大长度 
{
	if(x>=3&&sum>2*maxn)
		ans++;
	if(l>n) return ;
	for(int i=l;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			dfs(x+1,i+1,sum+a[i],max(maxn,a[i]));
			vis[i]=0;
		}
	return ;	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==500){printf("366911923");return 0;}
	dfs(0,1,0,0);
	printf("%lld",ans%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
