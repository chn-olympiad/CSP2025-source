#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int Maxn=505,Mod=998244353;
int n,m;
int id[Maxn],c[Maxn];
ll f[1<<18|5][20];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%1d",&id[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		int o=__builtin_popcount(i);
		for(int j=0;j<n;j++){
			if(!(i>>j&1)){
				for(int k=0;k<=o;k++){
					f[i^(1<<j)][k+(c[j+1]>o-k)]+=f[i][k];
					f[i^(1<<j)][k+(c[j+1]>o-k)]%=Mod;
				}
				
			}
		}
	}
	ll ans=0;
	for(int i=m;i<=n;i++) ans+=f[(1<<n)-1][i],ans%=Mod;
	printf("%lld",ans);

	return 0;
}
/*
计数题
插入DP 

暴力有 20pts

时间复杂度 O(n^3)。 

3 2
101
1 1 2

 
*/
