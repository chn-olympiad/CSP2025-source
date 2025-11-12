#include<bits/stdc++.h>
#define int long long
#define popc(x) __builtin_popcount(x)
using namespace std;
bool Mst;
const int N=510;
const int mod=998244353;
int n,m;
int c[N];
int cnt[N];
char S[N];
int f[(1<<18)+10][19];
int fact[N],ni[N];

int qpow(int x,int k)
{
	int res=1;
	while(k)
	{
		if(k&1) res=res*x%mod;
		x=x*x%mod,k>>=1;
	}
	return res;
}

void add(int & x,int y)
{
	x=x+y>=mod?x+y-mod:x+y;
}

int C(int x,int y)
{
	if(y<0 || y>x) return 0;
	return fact[x]*ni[y]%mod*ni[x-y]%mod;
}

bool Med;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",S+1);
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		cnt[c[i]]++;
	}
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	ni[n]=qpow(fact[n],mod-2);
	for(int i=n;i;i--) ni[i-1]=ni[i]*i%mod;
	if(n<=18)
	{
		f[0][0]=1;
		for(int s=0;s<(1<<n);s++)
		{
			int cnt=popc(s);
			for(int i=0;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(s&(1<<(j-1))) continue;
					int k=i+(S[cnt+1]=='0' || c[j]<=i);
					add(f[s+(1<<(j-1))][k],f[s][i]);
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++)
		{
			add(ans,f[(1<<n)-1][n-i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==1)
	{
		int ans=fact[n];
		int sum=0,tmp=1,sum1=0;
		for(int i=1;i<=n;i++)
		{
			sum=sum+cnt[i-1];
			if(S[i]=='0') continue;
			tmp=tmp*(sum-sum1)%mod;
			sum1++;
		}
		ans=(ans+mod-tmp*fact[n-sum1]%mod)%mod;
		cout<<ans<<endl;
		return 0;
	}
	if(m==n)
	{
		int ans=fact[n];
		for(int i=1;i<=n;i++)
		{
			if(S[i]=='0' || c[i]==0)
			{
				ans=0;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
}
/*
employ
1、BF 2^n +20
2、A性质 n^3
3、B性质 2^18
4、m=1 n^2 +12
5、m=n O(n) +4

g++ employ.cpp -o employ.exe
./employ.exe


*/
