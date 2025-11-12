#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e+05+10;
ll a[N],s[N];
bool f[N];
ll z(ll x,ll y)
{
	return x>y?x-y:y-x;
}
bool check(int l,int r)
{
	bool q=1;
	for(int i=l;i<=r;i++){if(f[i]){q=0;break;}}
	return q;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int i,j;
	bool fl=1;
	ll n,k,ans=0,sum=0;
	scanf("%lld%lld",&n,&k);
	s[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s[i]=s[i-1]^a[i];
		if(a[i]>1) fl=0;
		if(a[i]==k) f[i]=1,ans++;
		sum+=a[i];
	}
	if(fl)
	{
		printf("%lld",sum);
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(z(s[j],s[i-1])==k)
			{
				if(check(i,j))
				{
					ans++;
					for(k=i;k<=j;k++) f[k]=1;
				}
			}
		}
	}
	printf("%lld",ans);
}
