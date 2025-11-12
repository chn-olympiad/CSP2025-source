#include<bits/stdc++.h>
#define int long long
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define dow(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int N=5005,M=505,p=998244353;
int n,a[N],ans;
int f[M*M];
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		b>>=1,a=a*a%p; 
	}
	return res;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>500) {cout<<(((qpow(2,n)-(n+1)*n/2%p-1)%p)+p)%p;return 0;}
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	rep(i,1,n)
	{
		rep(j,a[i]+1,a[i]*i)
		  ans+=f[j],ans%=p;
		dow(j,a[i]*i,a[i]+1)
		  f[j]+=f[j-a[i]],f[j]%=p;
		f[a[i]]++;
//		rep(j,1,a[n]*n) cout<<g[j]<<" ";
//		cout<<endl;
//		cout<<ans<<endl;
	}
//	rep(i,a[n]*2+1,n*n)
//      if(f[i]!=-1)
//        ans+=f[i],ans%=p;
	cout<<ans;
	return 0;
}