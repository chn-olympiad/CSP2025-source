#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll jc[510];
char s[510];
int c[510];
ll v[510];
bool b[510];
int a[510];
ll ans=0;
const ll mod=998244353;
inline void dfs(int k)
{
	if(k>n)
	{
		int cnt=0,sum=0;
		for(register int i=1;i<=n;i++)
		{
			if(s[i]=='0'){cnt++;continue;}
			if(cnt>=c[a[i]]){cnt++;continue;}
			sum++;
		}
		if(sum>=m) ans++;
		return;
	}
	for(register int i=1;i<=n;i++) if(!b[i]) b[i]=1,a[k]=i,dfs(k+1),b[i]=0;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	jc[0]=1;
	for(register int ll i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
	for(register int i=1;i<=n;i++) cin>>s[i];
	for(register int i=1;i<=n;i++) scanf("%d",&c[i]),v[c[i]]++;
	if(m==1)
	{
		ll sum=0,ss=0,sss=1,ssss=0;int cnt=0;
		for(register int i=1;i<=n;i++)
		{
			ss+=v[i-1],ssss+=v[i-1];
			if(s[i]=='1')
			{
				cnt++;
				sum=(sum+sss*(1ll*n-ssss)%mod*jc[n-cnt]%mod)%mod;
				sss=sss*ss%mod,ss--;
			}
		}
		printf("%lld\n",sum);
		return 0;
	}
	if(m==n)
	{
		int fl=1;
		for(register int i=1;i<=n;i++) if(s[i]=='0'){fl=0;break;}
		if(!fl){puts("0");return 0;}
		ll ss=0,sss=1;
		for(register int i=n;i>=1;i--) ss+=v[i],sss=sss*ss%mod,ss--;
		printf("%lld\n",sss);
		return 0;
	}
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
//¸ÃĞÑĞÑÁË¡£ 
