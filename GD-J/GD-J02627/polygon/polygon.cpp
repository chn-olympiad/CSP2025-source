#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,md=998244353,a[1000001],ans,mx,cnt[1000001],f[100001],g[100001];
vector<int>w;
int ksm(int x,int y)
{
	int res=1;
	while(y>0)
	{
		if(y&1) res=res*x%md;
		x=x*x%md;
		y>>=1;
	}
	return res;
 } 
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]),cnt[a[i]]++;
	sort(a+1,a+1+n);
	f[0]=1;
	for(int j=1;j<=n;j++)
	{
		for(int k=a[n];k>=a[j];k--) 
		{
			f[k]+=f[k-a[j]];
			f[k]%=md;
		}
	}
	for(int i=1;i<=a[n];i++) g[i]=g[i-1]+f[i],g[i]%=md;
//	for(int j=2;j<=a[n];j++) cout<<g[j]<<" ";
//	cout<<endl; 
	for(int i=1;i<=n;i++)
	{
		ans=(ans+(ksm(2,i-1)-g[a[i]]-1+cnt[a[i]])%md+md)%md;
		cnt[a[i]]--;
	}
	cout<<ans;
}
