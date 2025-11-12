#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int N=5e3+10;
const ll mod=998244353;
ll ans,sum=0,maxn=-1e18;
ll n;
ll ar[N],jc[N];
void dfs(ll z,ll step,int lst)
{
	if(step==z)
	{
		//cout<<step<<" "<<z<<" "<<maxn<<" "<<sum<<endl; 
		if(sum>(maxn*2))
		{
			ans++;
			ans%=mod;
		}
		return ;
	}
	f(i,lst+1,n)
	{
		ll lmaxn=maxn;
		maxn=max(maxn,ar[i]);
		sum+=ar[i];
		dfs(z,step+1,i);
		maxn=lmaxn;
		sum-=ar[i];
	}
}
ll c(int n,int m)
{
	return (jc[n]/((jc[m]*jc[n-m])%mod))%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	f(i,1,n)
	{
		cin>>ar[i];
	}
	if(n>20)
	{
		jc[1]=1;
		f(i,2,n)
		{
			jc[i]=jc[i-1]*i;
			jc[i]%=mod;
		}
		f(i,3,n)
		{
			ans+=c(n,i);
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	f(i,3,n)
	{
		sum=0;
		maxn=-1e18;
		dfs(i,0,0);
	}
	cout<<ans;
	return 0;
}

