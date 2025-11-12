#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=505;
const int MOD=998244353;
inline int gsc(int X,int P){int ret=1;for(;P;P>>=1,X=1LL*X*X%MOD)if(P&1)ret=1LL*ret*X%MOD;return ret;}
int N,M;
char s[maxn];
int a[maxn],cnt1;
int sum[maxn];
inline void SpecialA();
inline void BaoLi(){
	
}
int main(){
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout);
	scanf("%d %d %s",&N,&M,s+1);
	for(int i=1;i<=N;i++)scanf(" %d",&a[i]);
	for(int i=1;i<=N;i++)if(s[i]=='1')cnt1++;
	if(N<=10){BaoLi();return 0;}
	if(cnt1==N){SpecialA();return 0;}
	return 0;
}
inline void SpecialA(){int ansSA=1;for(int i=1;i<=N;i++)ansSA=1LL*ansSA*i%MOD;printf("%d",ansSA);}
/*
@CEFqwq 最可爱啦！她一定一定能去到致远的蓝天之上，那是我究其一生也达不到的梦想。 
*/
