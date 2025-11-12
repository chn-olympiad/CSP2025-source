#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define p 998244353

typedef long long ll;

inline void add(int &x,int y)
{
	x+=y;
	if(x>=p) x-=p;
}
inline int qpow(int x,int y)
{
	int res=1;
	for(;y>0;y>>=1,x=1ll*x*x%p) res=y&1?1ll*res*x%p:res;
	return res;
}

const int S=505;

int fra[S],inv[S],C[S][S];
int n,m;
char a[S];
int cnt[S],sm[S];
int f[2][S][S]; 

int main()
{
	fra[0]=1;
	for(int i=1;i<=S-3;i++) fra[i]=1ll*fra[i-1]*i%p;
	inv[S-3]=qpow(fra[S-3],p-2);
	for(int i=S-3;i>=1;i--) inv[i-1]=1ll*inv[i]*i%p;
	for(int i=0;i<=S-3;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
	}
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>a;
	for(int i=n;i>=1;i--) a[i]=a[i-1]-'0';
	for(int i=1,x;i<=n;i++) cin>>x,cnt[x]++;
	sm[0]=cnt[0];
	for(int i=1;i<=n;i++) sm[i]=sm[i-1]+cnt[i];
	f[0][0][0]=1;
	int c0=0,c1=0;
	for(int i=1;i<=n;i++)
	{
		int u=i&1,v=u^1;
		memset(f[u],0,sizeof(f[u]));
		for(int j=0;j<=c1;j++)
			for(int k=0;k<=c1-j;k++)
			{
				int die=c0+j;
				if(a[i]==0)
				{
					for(int x=0;x<=c1-j-k&&x<=cnt[die+1];x++)
					{
						add(f[u][j][k+x],1ll*f[v][j][k]*
							C[cnt[die+1]][x]%p*C[c1-j-k][x]%p*fra[x]%p);
					}
				}
				else
				{
					add(f[u][j][k],f[v][j][k]);
					for(int x=0;x<=c1-j-k&&x<=cnt[die+1];x++)
					{
						add(f[u][j+1][k+x],1ll*f[v][j][k]*(sm[die]-j-k)%p*
							C[cnt[die+1]][x]%p*C[c1-j-k][x]%p*fra[x]%p);
					}
				}
			}
		c0+=1-a[i],c1+=a[i];
	}
	int ans=0;
	for(int j=0;j<=c1;j++)
		for(int k=0;k<=c1-j;k++)
			if(c1-j>=m)
			{
				add(ans,1ll*f[n&1][j][k]*
					C[n-sm[c0+j]][c1-j-k]%p*fra[c1-j-k]%p*fra[c0]%p);
			}
	cout<<ans<<'\n';
	return 0;
}
