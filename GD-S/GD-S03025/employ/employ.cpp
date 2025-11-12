#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
const int N=5e2+5,S=(1<<18);
const int N1=25;
int n,m;
int f[N1][N1][S];
int c[N];
int ans;
char ch[N]; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",ch+1);
	for(int i=1; i<=n; i++){
		scanf("%d",&c[i]);
	}
	int sc=0;
	for(int i=1; i<=n; i++){
		sc+=ch[i]-'0';
	} 
//	if(sc==n){
//		
//		return 0;
//	}
	f[0][0][0]=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			for(int s=0; s<(1<<n); s++){
				for(int k=1; k<=n; k++){
					if((s>>(k-1))&1) continue;
					if(ch[i+1]=='0'){
						f[i+1][j+1][s|(1<<(k-1))]=(f[i+1][j+1][s|(1<<(k-1))]+f[i][j][s])%mod;
					}else{
						if(j<c[k]){
							f[i+1][j][s|(1<<(k-1))]=(f[i+1][j][s|(1<<(k-1))]+f[i][j][s])%mod;
						}else{
							f[i+1][j+1][s|(1<<(k-1))]=(f[i+1][j+1][s|(1<<(k-1))]+f[i][j][s])%mod;
						}
					}
				}
			}
		}
	}
	for(int i=m; i<=n; i++){
		ans=(ans+f[n][n-i][(1<<n)-1])%mod;
	}
	printf("%d",ans);
	return 0;
}
