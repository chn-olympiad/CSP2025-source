#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long ans;
int n;
int a[5050],b[5050],d[5050];
int calc(int p,int q)
{
	int ans=1;
	for(int i=1;i<=q;i++)
	{
		ans=ans*(p-i+1)%mod;
	}
	for(int i=q;i>=2;i--)
	{
		ans=ans/i;
	}
	//printf("%d\n",ans+1);
	return ans;
}
void dfs(int x,int s)
{
	if(s-a[x]<0)
	{
		//for(int i=1;i<=step;i++)
		//	printf("%d ",d[i]);
		//printf("s:%d",)
		//printf("\n");
		ans++;
		/*for(int i=0;i<=x-1;i++)
		{
			ans+=calc(x-1,i)%mod;
		}*/
		ans%=mod;
		//return;
	}
	if(x==1)return;
	for(int i=x-1;i>=1;i--)
	{
		dfs(i,s-a[x]);
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(a[n]==1 and n>3)
	{
		for(int i=3;i<=n-2;i++)
		{
			ans+=(1+i-2)*(i-2)%mod/2;
		}
		printf("%lld",ans%mod);
	}
	else
	{
		for(int i=3;i<=n;i++)
			dfs(i,a[i]*2);
		printf("%lld",ans%mod);
	}
	/*for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1])
			d[a[i-1]]=i-1;
	}
	for(int i=n;i>=3;i--)
	{
		for(int j=i-1;j>=2;j--)
		{
			if(a[j]<=a[i]/2)break;
			if(a[j]+a[j-1]<=a[i])break;
			int t=a[i]-a[j],f;
			while(d[t]==0)t--;
			f=d[t]+1;
			printf("%d %d\n",a[i],a[j]);
			ans+=(f+j-1)*(j-f)%mod/2;
		}
	}*/
	return 0;
}

