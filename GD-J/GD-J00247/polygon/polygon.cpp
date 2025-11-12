#include<bits/stdc++.h>
#define mo 998244353
using namespace std;
long long a[5401],n,ans;
long long C[5401][5401];
void clear()
{
	C[1][1]=1;
	for(long long i=1;i<=n;i++) C[i][1]=C[i][i]=1;
	for(long long i=2;i<=n;i++)
		for(long long j=2;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
}
void dg(long long k,long long sum,long long maxn,bool changed)
{
	if(k-1>=3&&sum>maxn*2&&changed) ans=(ans+1)%mo;
	if(k>n) return;
	dg(k+1,sum+a[k],a[k],true);
	dg(k+1,sum,maxn,false);
}
void fre()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
}
signed main()
{
	fre();
	cin>>n;
	clear();
	bool flag=true;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++) flag=(a[i]==a[i-1]&&flag);
	if(a[n]==1||flag) for(long long i=3;i<=n;i++) ans=(ans+C[n-1][i-1])%mo;
	else dg(1,0,0,false);
	cout<<ans;
	return 0;
}
