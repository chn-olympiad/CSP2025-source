#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[20],f[1<<18][20];
char S[20];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",S+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	f[0][0]=1;
	for(int i=0;i<(1<<n)-1;i++){
		int cc=1;
		for(int j=0;j<n;j++) cc+=((i>>j)&1);
		for(int j=0;j<n;j++){
			for(int l=0;l<n;l++){
				if((i>>l)&1) continue;
				if(S[cc]=='1'&&c[l+1]>j){
					f[i^(1<<l)][j]+=f[i][j];
					if(f[i^(1<<l)][j]>=mod) f[i^(1<<l)][j]-=mod;
				}else{
					f[i^(1<<l)][j+1]+=f[i][j];
					if(f[i^(1<<l)][j+1]>=mod) f[i^(1<<l)][j+1]-=mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++) (ans+=f[(1<<n)-1][i])%=mod;
	printf("%d",ans);
	return 0;
}

