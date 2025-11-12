#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
long long cnt[555];
long long n,m,a[555],f=1;
char s[555];
long long findout(long long x)
{
	long long l=1,r=n,ans=0;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(a[mid]<=x) ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
long long T(long long x)
{
	long long ans=1;
	for(long long i=1;i<=n;i++) ans=(ans*i)%mo;
	return ans%mo;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;scanf("%s",s+1);
	for(long long i=1;i<=n;i++) a[i]=(s[i]=='1'),f=f&a[i];
	for(long long i=1;i<=n;i++) cin>>cnt[i];
	sort(cnt+1,cnt+1+n);
	if(f) cout<<T(n);
	else if(m==n) cout<<T(n)*f;
	else if(m==1)
	{
		long long u=0;
		for(long long i=1;i<=n;i++)
			if(a[i]==1)
				u=max(u,1ll),u=u*T(n-findout(i)+1)%mo;
		cout<<u;
	}
	else cout<<0;
	return 0;
}
