#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=505, M=20, MOD=998244353;

int n,m;
char s[N];
int a[N],c[N];

void Solve1(){
	for(int i=1;i<=n;i++)
		if(a[i]==0 || c[i]==0){
			printf("0");
			return;
		}
	LL ans=1;
	for(int i=1;i<=n;i++) ans=ans*i%MOD;
	printf("%lld",ans);	
}

LL f[1<<M][M];
void Solve2(){
	int mx=(1<<n)-1;
	for(int i=1;i<=n;i++){
		if(a[1]=='0' || c[i]==0) f[1<<(i-1)][1]=1;
		else f[1<<(i-1)][0]=1;
	}
	for(int i=1;i<=mx;i++){
		int sum=0;
		for(int j=1;j<=n;j++) if(i&(1<<(j-1))) sum++;
		for(int k=0;k<=sum;k++)
			for(int j=1;j<=n;j++){
				if((i>>(j-1))&1) continue;
				int nw=i|(1<<(j-1));
				if(k>=c[j] || a[sum+1]==0) f[nw][k+1]=(f[nw][k+1]+f[i][k])%MOD;	
				else f[nw][k]=(f[nw][k]+f[i][k])%MOD;
			}
	}
	LL zans=0;
	for(int i=0;i<=n-m;i++) zans=(zans+f[mx][i])%MOD;
	printf("%lld",zans);
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++) a[i]=s[i]-'0';
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	
	if(m==n){
		Solve1();
		return 0;
	}
	
	Solve2();
	return 0;
}

