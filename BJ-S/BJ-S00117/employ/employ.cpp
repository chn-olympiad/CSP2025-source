#include<iostream>
#include<fstream>
using namespace std;
typedef long long LL;
const int N=20,K=500010,mod=998244353;
char s[N];
int f[K][N];
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=0;i<n;++i)
		scanf("%d",&c[i]);
	f[0][0]=1;
	for(int state=0;state<1<<n;++state){
		int cnt=0;
		for(int p=0;p<n;++p)
			if(state>>p&1)
				++cnt;
		for(int p=0;p<n;++p){
			if(!(state>>p&1))
				continue;
			int pstate=state-(1<<p);
			for(int i=0;i<cnt;++i)
				if(s[cnt]=='0'||c[p]<=cnt-1-i)
					f[state][i]=(f[state][i]+f[pstate][i])%mod;
				else
					f[state][i+1]=(f[state][i+1]+f[pstate][i])%mod;
		}
	}
	int res=0;
	for(int i=m;i<=n;++i)
		res=(res+f[(1<<n)-1][i])%mod;
	printf("%d",res);
	return 0;
}