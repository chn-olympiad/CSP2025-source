#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define bll __int128
#define vii vector<int>
#define pb push_back
#define ppb pop_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define fi first
#define sec second
#define Qii queue<int>
#define vll vector<ll>
#define vpi vector<pii>
#define ci const int
using namespace std;
const int N=505,mod=998244353;
int n,m;
string str;
int c[N],myc[N][N];
int fac[N],ifac[N];
void add(int&x,int y){x+=y;if(x>=mod)x-=mod;}
void sub(int&x,int y){x-=y;if(x<0)x+=mod;}
int Add(int x,int y){x+=y;if(x>=mod)x-=mod;return x;}
int Sub(int x,int y){x-=y;if(x<0)x+=mod;return x;}
ll C(int x,int y){if(x<y)return 0;return myc[x][y];}
ll ksm(ll x,int y){ll z=1;while(y){if(y&1)z=z*x%mod;x=x*x%mod,y>>=1;}return z;}
int f[N][N],g[N][N];
int s[N],S[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1;for(int i=1;i<=500;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=0;i<=500;i++)ifac[i]=ksm(fac[i],mod-2);
	for(int i=0;i<=500;i++)for(int j=0;j<=i;j++)myc[i][j]=1ll*fac[i]*ifac[j]%mod*ifac[i-j]%mod;
	scanf("%d%d",&n,&m);
	cin>>str,str=' '+str;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)s[c[i]]++;
	for(int i=0;i<=n;i++)S[i]=s[i];
	for(int i=1;i<=n;i++)S[i]+=S[i-1];
	g[0][s[0]]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<=n;k++)
			{
				if(!g[j][k])continue;
				if(str[i]=='1')
				{
					add(f[j][k],g[j][k]);
					if(k)
					{
						for(int l=0;l<=s[j+1];l++)
						{
							add(f[j+1][k-1+l],1ll*g[j][k]*C(i-1-(S[j]-k),s[j+1]-l)%mod*k%mod*fac[s[j+1]-l]%mod*C(s[j+1],l)%mod);
						}
					}
				}
				else
				{
					if(k)
					{
						for(int l=0;l<=s[j+1];l++)add(f[j+1][k-1+l],1ll*g[j][k]*C(i-1-(S[j]-k),s[j+1]-l)%mod*k%mod*fac[s[j+1]-l]%mod*C(s[j+1],l)%mod);
					}
					for(int l=0;l<=s[j+1];l++)add(f[j+1][k+l],1ll*g[j][k]*C(i-(S[j]-k),s[j+1]-l)%mod*fac[s[j+1]-l]%mod*C(s[j+1],l)%mod);
				}
			}
		}
		for(int j=0;j<=i;j++)for(int k=0;k<=n;k++)g[j][k]=f[j][k],f[j][k]=0;
	}
	int ans=0;
	for(int j=0;j<=n-m;j++)add(ans,1ll*g[j][0]*fac[S[n]-S[j]]%mod);
	printf("%d",ans);
}

