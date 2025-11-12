#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e3+3;
const ll Mod=998244353;
int n,a[N],maxx;
ll f[N],ans;
ll cj[N],inv[N];
void qs(int i,int j)
{
	int l=i,r=j,mid=a[(i+j)>>1];
	while(i<=j)
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++,j--;
		}
	}
	if(l<j) qs(l,j);
	if(i<r) qs(i,r);
}
void dfs(int x,int gs,int num)
{
	if(x>n)
	{
		return;
	}
	if(gs<2)
	{
		dfs(x+1,gs,num);
		dfs(x+1,gs+1,num+a[x]);
	}
	else
	{
		if(num>a[x]) ans++;
		dfs(x+1,gs,num);
		dfs(x+1,gs+1,num+a[x]);
	}
}
ll ksm(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1) res=res*x%Mod;
		x=x*x%Mod;
		y>>=1;
	}
	return res;
}
ll C(int x,int y)
{
	return cj[x]*inv[y]%Mod*inv[x-y]%Mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
	}
	qs(1,n);
	if(n<=20)
	{
		dfs(1,0,0);
		printf("%lld",ans);
		return 0;
	}
	bool sf=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)
		{
			sf=1;
			break;
		}
	}
	if(!sf)
	{
		cj[0]=1;
		for(int i=1;i<=n;i++)
			cj[i]=(ll)i*cj[i-1]%Mod;
		inv[n]=ksm(cj[n],Mod-2);
		inv[0]=1;
		for(int i=n-1;i>=1;i--)
			inv[i]=(ll)(i+1)*inv[i+1]%Mod;
//		for(int i=1;i<=n;i++)
//			printf("%d  %lld %lld\n",i,cj[i],inv[i]);
		for(int i=3;i<=n;i++)
		{
			ans=(ans+C(n,i))%Mod;
//			printf("%d %lld %lld %lld %lld\n",i,C(n,i),cj[n],inv[i],inv[n-i]);
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=maxx+1;j>=1;j--)
		{
			if(j>a[i])
			{
				ans=(ans+f[j])%Mod;
			}
			int tmp=min(maxx+1,a[i]+j);
			f[tmp]=(f[tmp]+f[j])%Mod;
		}
		for(int j=1;j<i;j++)
		{
			f[min(maxx+1,a[i]+a[j])]++;
		}
//		printf("%d %d\n",i,ans);
//		printf("%d\n",i);
//		for(int j=1;j<=maxx+1;j++)
//			printf("%d %d\n",j,f[j]);
	}
//	for(int i=1;i<=maxx+1;i++)
//	{
//		ans=(ans+f[i])%Mod;
////		printf("%d %lld\n",i,f[i]);
//	}
//	ans=(ans-n*(n-1)/2+Mod)%Mod;
	printf("%lld",ans);
	return 0;
}
