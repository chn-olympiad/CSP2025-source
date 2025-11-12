#include<bits/stdc++.h>
using namespace std;
const int N=505,M=(1<<18)+5,mod=998244353;
int n,m,ans;
int c[N],f[2][19][M];
char s[N];
vector<int> vec[19];
int calc(int x)
{
	int res=0;
	while(x) res+=(x&1),x>>=1;
	return res;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(n<=18)
	{
		for(int i=0;i<(1<<n);i++) vec[calc(i)].push_back(i);
		f[0][0][0]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				for(int p=0;p<vec[i].size();p++)
				{
					int zt=i&1,k=vec[i][p];
					for(int t=0;t<n;t++)
					{
						if(!(k&(1<<t)))
						{
							if(i-j>=c[t+1]||s[i+1]=='0') (f[zt^1][j][k|(1<<t)]+=f[zt][j][k])%=mod;
							else (f[zt^1][j+1][k|(1<<t)]+=f[zt][j][k])%=mod;
						}
					}
					f[zt][j][k]=0;
				}
			}
		}
		for(int i=m;i<=n;i++) ans=(ans+f[n&1][i][(1<<n)-1])%mod;
		printf("%d",ans);
	}
	return 0;
}
