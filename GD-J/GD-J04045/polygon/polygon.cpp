#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define N 5010
#define M 25000010
#define mod 998244353
using namespace std;
inline long long read()
{
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int a[N],n,s[M],c[M],f[N],sum[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	if(n==3)
	{
		if(a[1]+a[2]>a[3]) printf("1");
		else printf("0");
		return 0;
	}
	if(a[1]+a[2]>a[3]) f[3]=1;
	c[a[1]]++;c[a[2]]++;c[a[3]]++;c[a[1]+a[2]]++;c[a[1]+a[3]]++;c[a[2]+a[3]]++;c[a[1]+a[2]+a[3]]++;
	for(int i=sum[3];i>=1;i--) s[i]=s[i+1]+c[i];
	for(int i=4;i<=n;i++)
	{
		f[i]=(f[i-1]+s[a[i]+1])%mod;
		for(int j=sum[i-1]+a[i];j>=1;j--) c[j]=(c[j]+c[j-a[i]])%mod;
		for(int j=sum[i];j>=1;j--) s[j]=(s[j+1]+c[j])%mod;
	}
	printf("%lld\n",f[n]);
	return 0;
}

