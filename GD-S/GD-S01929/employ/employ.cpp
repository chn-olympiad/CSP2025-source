#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
using namespace std;
const int mod=998244353;
const int N=19;
int n,m;
int f[1<<N][N];
char c[N];
int a[N],cnt[N];
int count(int x)
{
	int cnt=0;
	while(x)
	{
		cnt+=(x&1);
		x>>=1;
	}
	return cnt;
}
int res;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	scanf("%d%d%s",&n,&m,c+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[0][0]=1;
	for(int mask=1;mask<(1<<n);mask++)
	{
		int num=count(mask);
		for(int k=1;k<=n;k++)
			if(mask&(1<<k-1))
			{
				for(int j=0;j<=m;j++)
				{
					int w=((num-j<a[k])&&(c[num]&1));
					if(j>=w) f[mask][j]=(f[mask][j]+f[mask^(1<<k-1)][j-w])%mod;
				}
			}
	}
	for(int i=m;i<=n;i++)
		res=(res+f[(1<<n)-1][i])%mod;
	printf("%d",res); 
	return 0;
}
