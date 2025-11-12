#include<cstdio>
#include<cstdlib>
typedef long long LL;
const int N=5e5+3, U=1<<20;//数字出现：[0, U)（U=1048576） 
int n; signed k,a[N];
int iuxm[U], nxt[N];//iuxm[x]: x最晚出现在哪里（-1表示没出现） 
//取名iuxm因为我用自然码双拼打字，声母：i->ch, x->x；韵母：u->u，m->ian，因此iuxm = “出现”
//nxt[i]: 找到一个整数j，使得a[j] XOR a[i] XOR k=0，j<i，求j的最大值 
int dp[N];//dp：a[1..i]最多能选到几个区间，a[i]必须被选中 
int MAX(int x, int y) {return x>y? x:y; }
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	iuxm[0]=0; for(int i=1;i<U;++i) iuxm[i]=-1;//0在[0]位置出现了，因为一个数 xor 本身 = 0
	//而其他的没出现，就标记-1 
	scanf("%i%i",&n,&k);
	for(int i=1;i<=n;++i) {
		scanf("%i",&a[i]); a[i]^=a[i-1];//前缀和 
		nxt[i]=iuxm[a[i] xor k], iuxm[a[i]]=i;//构建&更新iuxm 
	}
	for(int i=1;i<=n;++i) {
		if(nxt[i]==-1) dp[i]=0;//没出现（必须特判） 
		else dp[i]=dp[nxt[i]]+1;//出现了 
		dp[i]=MAX(dp[i],dp[i-1]);
	} printf("%i",dp[n]);
	return 0;
}
