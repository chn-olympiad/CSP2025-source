#include<stdio.h>
#include<algorithm>
#include<string.h>
#define int long long
using namespace std;
const int Mod=998244353;
int C[505][505];
void init()
{
	for(int i=0;i<=500;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	}
}
bool s[505];
char opt[505];
int n,m,c[505],d[505],f[505][505][505];
int t[505],ans;
inline int low(int x){return x&(-x);}
void Add(int x,int d){while(x<=n)t[x]+=d,x+=low(x);}
int Query(int x)
{
	int sum=0;
	while(x)sum+=t[x],x-=low(x);
	return sum;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	scanf("%lld %lld\n%s",&n,&m,opt+1);
	for(int i=1;i<=n;i++)s[i]=(opt[i]=='1');
	for(int i=2;i<=n+1;i++)d[i]=d[i-1]+(int)(!s[i]);
	for(int i=1;i<=n;i++)scanf("%lld",c+i),Add(c[i],1);
	f[1][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<=i;k++)
			{
				int tmp=f[i][j][k];
				//~ printf("%lld %lld %lld %lld %lld\n",i,j,k,f[i][j][k],Query(n)-Query(j+k+d[i]));
				if(s[i]==0)(f[i+1][j][k+1]+=tmp)%=Mod,(f[i+1][j+1][k]+=tmp)%=Mod;
				else{
					if(k>0){
						(f[i+1][j+1][k-1]+=tmp*(C[Query(j+k+d[i])-j-1][1])%Mod)%=Mod;
					}
					(f[i+1][j+1][k-1]+=tmp*(C[Query(j+k+d[i])-j][1])%Mod)%=Mod;
					(f[i+1][j][k]+=tmp*(C[Query(n)-Query(j+k+d[i])-k][1]%Mod))%=Mod;
					//~ for(int k1=0;k1<=k;k1++)(f[i+1][j+k1+1][k-k1]+=tmp*(C[Query(j+k)-j][k1+1])%Mod)%=Mod;
					
				}
			}
		}
	}
	for(int j=0;j+d[n+1]<=n-m;j++)for(int k=0;k+j+d[n+1]<=n-m;k++)(ans+=f[n+1][j][k]*C[Query(n)-Query(j+k+d[n+1])][1]%Mod)%=Mod;
	printf("%lld",ans);
	return 0;
}
