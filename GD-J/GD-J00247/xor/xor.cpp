#include<bits/stdc++.h>
using namespace std;
struct asd{
	long long l;
	long long r;
}b[500501];
long long len;
long long n,k,a[500501],sum[500501];
long long cmp(asd x,asd y)
{
	if(x.l!=y.l) return x.l<y.l;
	else if(x.r-x.l!=y.r-y.l) return x.r-x.l<y.r-y.l;
	else return x.r<y.r;
}
void fre()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
}
signed main()
{
	fre();
	cin>>n>>k;
	for(long long i=1;i<=n;i++) cin>>a[i];
	bool flag=(k==0),flag2=(k<=1);
	for(long long i=1;i<=n;i++) flag=(flag&&a[i]==1);
	for(long long i=1;i<=n;i++) flag2=(flag2&&0<=a[i]&&a[i]<=1);
	if(flag) cout<<(n-n%2)/2;
	else if(flag2)
	{
		long long ans=0;
		long long res1=0,res0=0;
		for(long long i=1;i<=n;i++)
			res1+=(a[i]==1),res0+=(a[i]==0);
		if(k==0)
		{
			ans+=res0;
			for(long long i=1;i<=n;i++)
				if(a[i]==1&&a[i-1]==1)
					a[i]=a[i-1]=0,ans++;
			cout<<ans;
		}
		else cout<<res1;
	}
	else
	{
		sum[0]=0;
		for(long long i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
		for(long long i=1;i<=n;i++)
			for(long long j=i;j<=n;j++)
				if((sum[j]^sum[i-1])==k)
					b[++len].l=i,b[len].r=j;
		sort(b+1,b+1+len,cmp);
		long long right=0,ans=0;
		for(long long i=1;i<=len;i++)
			if(b[i].l>right)
				ans++,right=b[i].r;
		cout<<ans;
	}
	return 0;
}
