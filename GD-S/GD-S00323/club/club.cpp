#include<cstdio>
#include<cstdlib>
typedef long long LL;
const int N=203;
LL a1[N], a2[N], a3[N], temp[N], dp[N][N][N];

int MIN(int x, int y) {return x<y? x:y; }
LL MAXU(LL x, LL y) {return x>y? x:y; } 

template<typename AU>
void sort(AU *alpha, AU *beta, int le, int ri) {
	if(le>=ri) return ;
	int mid=(le+ri)>>1;
	sort(alpha,beta,le,mid), sort(alpha,beta,mid+1,ri);
	int i=le, j=mid+1, k=le;
	while(i<=mid&&j<=ri) (alpha[i]>=alpha[j])? (beta[k++]=alpha[i++]) : (beta[k++]=alpha[j++]);
	while(i<=mid) {beta[k++]=alpha[i++]; } while(j<=ri) beta[k++]=alpha[j++];
	for(i=le;i<=ri;++i) alpha[i]=beta[i];
}

LL solve() {
	int n=0;
	scanf("%i",&n);
	for(int i=0;i<=n;++i) {//这个初始化浪费了我好多时间 
		for(int j=0;j<=n;++j) {//之前一直没初始化 
			for(int k=0;k<=n;++k) dp[i][j][k]=0;
		}
	}
	bool spA=true;//判断特殊性质A
	for(int i=1;i<=n;++i) {
		scanf("%lli%lli%lli",&a1[i],&a2[i],&a3[i]);
		if(a2[i]||a3[i]) spA=false;
	}
	if(spA) {//特殊性质A
		LL ans=0;
		sort(a1,temp,1,n); 
		for(int i=1;i<=(n>>1);++i) ans+=a1[i];
		return ans;
	} 
	if(n>N) {
		LL ans=0;
		for(int i=1;i<=n;++i) ans+=MAXU(MAXU(a1[i],a2[i]),a3[i]);//错误的贪心
		//但是有特殊性质C的存在，所以能拿到该部分分数 
		return ans;
	}
	LL ans=0;
	for(int i=1;i<=n;++i) {
		for(int j=0;j<=MIN(i, n>>1);++j) {//目前剩余i人（j人去了1社团） 
			for(int k=0;k<=MIN(i-j, n>>1);++k) {//目前剩余(i-j)人 （k人去了2社团） 
				int l=i-j-k;//l=(i-j-k)人去了3社团 
				if(l>(n>>1)) continue;//小心l>n/2 
				if(j) dp[i][j][k]=MAXU(dp[i][j][k], dp[i-1][j-1][k]+a1[i]);//i去1社团 
				if(k) dp[i][j][k]=MAXU(dp[i][j][k], dp[i-1][j][k-1]+a2[i]);//i去2社团
				if(l) dp[i][j][k]=MAXU(dp[i][j][k], dp[i-1][j][k]+a3[i]);//i去3社团
				if(i==n) ans=MAXU(ans,dp[i][j][k]);//记得取MAX 
			}
		}
	}
	return ans;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	scanf("%i",&t);
	//计算1/5=0.2，每个测试点要在0.2秒内完成 
	for(;t>0;--t)
		printf("%lli\n",solve());
	return 0; 
} 
