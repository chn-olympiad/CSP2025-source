#include<bits/stdc++.h>
#define gc getchar
#define il inline
using namespace std;
const int mod=998244353;
const int sz=500;
int n,m,c[sz+5];
char s[sz+5];
il int add(int x,int y){
	return x+y<mod?x+y:x+y-mod;
}
il int sub(int x,int y){
	return x<y?x+mod-y:x-y;
}
il int mul(int x,int y){
	return 1ll*x*y%mod;
}
int dp[18+5][(1<<18)+5],pc[(1<<18)+5],l,ans;
void solve1(){
	for(int i=1;i<(1<<n);i++) pc[i]=pc[i^(i&-i)]+1;
	dp[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<(1<<n);j++)
			for(int k=0;k<n;k++)
				if(!(j&(1<<k))){
					l=j|(1<<k);
					if(i>=c[k]||s[pc[j]]=='0') dp[i+1][l]=add(dp[i+1][l],dp[i][j]);
					else dp[i][l]=add(dp[i][l],dp[i][j]);
				}
	for(int i=0;i<=n-m;i++) ans=add(ans,dp[i][(1<<n)-1]);
	printf("%d\n",ans);
}
void solve2(){
	for(int i=0;i<n;i++)
		if(c[i]==0||s[i]=='0'){
			printf("0\n");
			return;
		}
	ans=1;
	for(int i=1;i<=n;i++) ans=mul(ans,i);
	printf("%d\n",ans);
}
int ans2,cnt[sz+5],sum;
int C[sz+5][sz+5]; 
void init(){
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=add(C[i-1][j-1],C[i-1][j]);
	}
}
void solve3(){
	init();
	ans=1;
	for(int i=1;i<=n;i++) ans=mul(ans,i);
	ans2=1;
	for(int i=0;i<n;i++){
		if(c[i]==n){
			printf("%d\n",ans);
			return;
		}
		++cnt[n-1-c[i]];
	}
	for(int i=0;i<n;i++){
		++sum;
		if(sum-cnt[i]<0){
			printf("%d\n",ans);
			return;
		}
		ans2=mul(ans2,C[sum][cnt[i]]);
	}
	printf("%d\n",sub(ans,ans2));
}
void solve4(){
	ans=1;
	for(int i=1;i<=n;i++) ans=mul(ans,i);
	printf("%d\n",ans);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) do s[i]=gc(); while(s[i]!='1'&&s[i]!='0');
	for(int i=0;i<n;i++) scanf("%d",&c[i]);
	if(n<=18) solve1();
	else if(n==m) solve2();
	else if(m==1) solve3();
	else solve4();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*欢迎来看luogu608273的大作rede 35,血海文书，失落之桥，失落遗迹。 ---如果还有时间，就应该挣扎到最后（ckk摘抄atri的名言）。*/
