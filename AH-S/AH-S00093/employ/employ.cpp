#include<bits/stdc++.h>
using namespace std;
const long long MAXN=5e2+5;
const long long MOD=998244353;
long long n,m,d[MAXN],c[MAXN],a[MAXN],have[MAXN],ans=1;
string problem;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>problem;
	for(long long i=0;i<n;++i) a[i+1]=problem[i];
	for(long long i=1;i<=n;++i) 
	{
		scanf("%lld",&c[i]);
		have[c[i]]++;
	}
	sort(c+1,c+n+1,cmp);
	long long ans_off=0;
	for(long long i=1;i<=n;++i)
	{
		ans_off+=1-a[i];
		if(ans_off>c[i]||a[i]==0)
		{
			ans_off++;
		}
		else
		{
			ans*=(c[i]-ans_off+1);
			ans%=MOD;
		}
	}
	printf("%lld",ans);
	return 0;
}
