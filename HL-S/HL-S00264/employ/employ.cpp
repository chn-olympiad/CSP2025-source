#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=19,mod=998244353;
int n,m,c[N],a[N],f[1<<N][N],cnt[1<<N];
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(int i=0;i<n;i++) a[i]=s[i]-'0';
	if(m==n){
		int ans=1;
		for(int i=0;i<n;i++){
			if(a[i]==0) printf("0"),exit(0);
			ans=1ll*ans*(i+1)%mod;
		}
		printf("%d\n",ans);
		return 0;
		
	}
	for(int i=0;i<(1<<n);i++){
		int j=i;
		while(j) cnt[i]+=(j&1),j>>=1;
	}
	f[0][0]=1;
	for(int i=0;i<n;i++) scanf("%d",&c[i]);
	for(int i=0;i<(1<<n);i++){
		int x=cnt[i];
		for(int k=0;k<=x;k++){
			for(int j=0;j<n;j++){
				if(i&(1<<j)) continue;
				if(k>=c[j]||a[x]==0) (f[i|(1<<j)][k+1]+=f[i][k])%=mod;
				else (f[i|(1<<j)][k]+=f[i][k])%=mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=(n-m);i++) (ans+=f[(1<<n)-1][i])%=mod;
	printf("%d\n",ans);
	return 0;
} 
