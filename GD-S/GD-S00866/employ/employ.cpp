#include<bits/stdc++.h>
using namespace std;
long long a,b,d[505],e[10][505][505],f[505],g;
char c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld %s",&a,&b,c+1);
	for(long long i=1;i<=a;i++){
		scanf("%lld",&d[i]);
		f[d[i]]++;
	}
	for(long long i=1;i<=a;i++){
		f[i]+=f[i-1];
	}
	e[0][0][0]=1;
	for(long long i=1;i<=a;i++){
		int l=i%2;
		for(long long j=0;j<=i;j++){
			for(long long k=0;k<=f[i-j];k++){
				if(c[i]=='1'){
					e[l][j][k]=e[l^1][j][k-1]*(f[i-1-j]-k+1)+e[l^1][j-1][k]*(a-i+1-f[i-j]+k);
					e[l][j][k]%=998244353;
				}
				else{
					e[l][j][k]=e[l^1][j][k-1]*(f[i-1-j]-k+1)+e[l^1][j][k]*(a-i+1-f[i-1-j]+k);
					e[l][j][k]%=998244353;
				}
			}
		}
	}
	for(long long i=b;i<=a;i++){
		for(long long j=1;j<=a;j++){
			g+=e[a%2][i][j];
			g%=998244353;
		}
	}
	printf("%lld",g);
	return 0;
}
