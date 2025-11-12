#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
char s[15];
long long a[15],vis[15],x[15],n,m,ans;
bool check()
{
	long long cnt=0,res=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0'||x[i+1]<=cnt)
			cnt++;
		else res++;
		//cout<<i<<" "<<ans<<" "<<x[i+1]<<" ";
	}
	//cout<<ans<<endl;
	return res>=m;
}
void dfs(int j)
{
	if(j>n)
	{
		if(check())
			ans=(ans+1)%M;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			x[j]=a[i];
			dfs(j+1);
			vis[i]=0;
			x[j]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
