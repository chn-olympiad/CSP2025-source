#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],b[500005],vis[500005],maxn=-114514;
void dfs(int cnt,int fontt)
{
	maxn=max(maxn,cnt);
	for(int i=fontt;i<=n;i++) for(int j=i;j<=n;j++) if((int)(b[j]^b[i-1])==k)
	{
		bool flag=true;
		for(int kk=i;kk<=j;kk++) if(vis[kk]==true) 
		{
			flag=false;
			break;
		}
		if(!flag) continue;
//		cout<<i<<' '<<j<<' '<<(b[j]^b[i-1])<<'\n';
		for(int kk=i;kk<=j;kk++) vis[kk]=true;
		dfs(cnt+1,j+1);
		for(int kk=i;kk<=j;kk++) vis[kk]=false;
	}
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=b[i-1]^a[i];
//		cout<<b[i]<<' ';
	}
	//1
	if(n<=2 && k==0)
	{
		puts("0");
		return 0;
	}
	//2
	if(n<=100)
	{
		dfs(0,1);
		cout<<maxn;
	}
	return 0;
}