#include <bits/stdc++.h>

using namespace std;

const int N=5e2+10,Mod=998244353;
char s[N];
long long n,m,c[N],res,vis[N],a[N],f[(1<<19)][20];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s+1);
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	if(n<=18)
	{
		f[0][0]=1;
		for(int i=0;i<(1<<n)-1;i++) 
		{
			int cnt=0;
			for(int j=0;j<n;j++) if((i>>j)&1) cnt++;
			for(int k=0;k<=cnt;k++) 
			{
				for(int j=0;j<n;j++) if(((i>>j)&1)==0) 
				{
					int op=1;
					if(cnt-k>=c[j+1]||s[cnt+1]=='0') op=0; 
					f[i+(1<<j)][k+op]=(f[i+(1<<j)][k+op]+f[i][k])%Mod;
				}
			}
		}
		for(int k=m;k<=n;k++) res=(res+f[(1<<n)-1][k])%Mod;
		printf("%lld",res);
	} 
	else if(m==n) 
	{
		int flag=1; 
		for(int i=1;i<=n;i++) if(s[i]=='0') flag=0;
		for(int i=1;i<=n;i++) if(c[i]==0) flag=0;
		if(flag==0) printf("0");
		else 
		{
			res=1;
			for(int i=1;i<=n;i++) res=res*i%Mod;
			printf("%lld",res);
		}
	}
	else printf("0");
	return 0;
} 