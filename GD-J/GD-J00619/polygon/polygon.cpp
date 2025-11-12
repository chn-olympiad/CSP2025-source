#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=998244353; 
int n,a[5005],ans,h[5005],h_[5005];
void dfs(int x,int y,int z,int w)
{
	if(w>=3&&y>z*2) ans++;
	for(int i=x+1;i<=n;i++)
	{
		dfs(i,y+a[i],max(z,a[i]),w+1);
	}
	return ;
}
int mi(int p,int q)
{
	int res=0;
	if(q==0) return 1;
	if(q==1) return p;
	if(q%2==0) return (mi(p,q/2)*mi(p,q/2))%Mod;
	else return (mi(p,q/2)*mi(p,q/2)*p)%Mod;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1)
	{
		h[0]=h_[0]=1;
		for(int i=1;i<=n;i++)
		{
			h[i]=(h[i-1]*i)%Mod;
		}
		for(int i=3;i<=n;i++)
		{
			ans+=h[n]/(h[i]*h[n-i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<ans%Mod<<endl; 
	return 0;
}
