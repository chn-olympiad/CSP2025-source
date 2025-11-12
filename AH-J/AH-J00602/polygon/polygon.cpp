#include<bits/stdc++.h>
using namespace std;
long long a[5005],b[5005];
long long n,s;
const long long mod=998244353;
void dfs(int x,int y,long long k,long long ma)
{
	if(x==n)
	{
		if(k>ma*2&&y>=3)
			s=(s+1)%mod;
		//cout<<k<<" "<<ma<<endl;
		return ;
	}
	dfs(x+1,y+1,k+a[x+1],max(ma,a[x+1]));
	dfs(x+1,y,k,ma);
}
void dfs2(int x,int y,int z)
{
	if(y==x)
		return ;
	if(z>a[x])
	{
		s=(s+b[x-y-1])%mod;
		return ;
	}
	dfs2(x,y+1,z+a[y+1]);
	dfs2(x,y+1,z);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	long long ma=0;
	b[0]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i],ma=max(ma,a[i]),b[i]=(b[i-1]*2)%mod;
	if(n<=20)
	{
		dfs(0,0,0,0);
		cout<<s;
		return 0;
	}
	if(ma==1)
	{
		long long x=1;
		for(int i=1;i<=n;i++)
			x=(x*2)%mod;
		x=(x+2*mod-n-(n-1)*n/2-1)%mod;
		cout<<x;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
		dfs2(i,0,0);
	cout<<s;
	return 0;
}
