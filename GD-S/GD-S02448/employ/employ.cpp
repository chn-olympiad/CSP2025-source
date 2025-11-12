#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
using namespace std;

const int N=20,mod=998244353;
int n,m;
char c[N];
int a[N];
int f[1<<18][N];
vector<int>p[N];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	scanf("%s",c+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(int i=0;i<1<<n;i++) p[__popcount(i)].pb(i);
	
	f[0][0]=1;
	for(int i=0;i<n;i++)
		for(int s:p[i])
			for(int j=0;j<=i;j++)
			{
				for(int k=1;k<=n;k++)
				{
					int flag=0;
					if(c[i+1]=='0') flag=1;
					else flag=(j>=a[k]);
					if(!(s&(1<<k-1)))
						(f[s|(1<<k-1)][j+flag]+=f[s][j])%=mod;
				}
			}
	int ans=0;
	for(int j=n-m;~j;j--) (ans+=f[(1<<n)-1][j])%=mod;
	printf("%d",ans);
	return 0;
}

