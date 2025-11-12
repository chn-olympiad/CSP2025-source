#include<bits/stdc++.h>
//#Shang4Shan3Ruo6Shui4
using namespace std;
const long long mod=998244353;
long long n,ans;
long long f[5010];
long long a[5010];
void DFS(long long k,long long sum,long long maxn)
{
	if(k==n)
	{
		if(sum>maxn*2) ans=(ans+1)%mod;
		return;
	}
	f[k+1]=1;
	DFS(k+1,sum+a[k+1],a[k+1]);
	f[k+1]=0;
	DFS(k+1,sum,maxn);
}
long long yh[5010][5010];
long long qpow(long long i,long long j){
	return yh[i][j];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	yh[0][0]=1;
	for(int i=1;i<=5000;i++)
	{
		for(int j=0;j<=i;j++) yh[i][j]=(yh[i-1][j]+yh[i-1][j-1])%mod;
	}
	long long F=true;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1) F=false;
	} 
	sort(a+1,a+1+n);
	if(F)
	{
		ans=0;
		for(int i=3;i<=n;i++)
		{
			for(int j=2;j<i;j++) ans=(ans+qpow(i-1,j))%mod;
		}
		cout<<ans;
	}
	else
	{
		DFS(0,0,0);
		cout<<ans;
	}
	return 0;
}

