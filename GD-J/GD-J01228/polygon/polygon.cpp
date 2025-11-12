#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
const int mod=998244353;
int n;
int a[maxn];
/*
当前已取数字和s，当前最大数mx 
那么，想要取a，a必须满足 s+a>2*max(a,mx)
我感觉可以先排个序
好像是dp？
那么定义dp[i][j]，表示当前已经拿了i个，最大值j，有几种选择 
先枚举j，从小到大吧，肯定从a3开始（前两个不可能是最大） 
我们就可以知道当这几个序列元素不大于j时的dp[i][j]
所以转移方程是...啥？
哦对，先初始化，对于每个j，统计可选的x个
dp[3][j]=C(2,x) 
等等那我怎么统计哪几个符合条件？
算了直接设j前面全都可以选，算完以后再减去不符合的
哦就是统计j前面有多少个数对(p,q)，p+q<=j
有道理
等一下这不就n^3了吗？不过这样还能拿17个点，值得一试 
加上二分，n^2logn还行
C(n,m)=n!/((n-m)!*m!)，打一个表应该就ok 
完了二分不好写，要统计多个
不管了n^3一把梭 
我右边那个已经摆烂了，现在剩下一小时
好了才回来搞转移方程
想不出来，先去写t3了
跳了，这题浪费我一小时
//froepen("polygon.in","r",stdin) 
我是蒟蒻 
*/
int dp[maxn][maxn];
long long jc[maxn];
void init(){
	memset(dp,0,sizeof(dp));
	memset(jc,0,sizeof(jc));
	jc[0]=1,jc[1]=1;
	for(int i=2;i<=5000;i++) jc[i]=jc[i-1]*i%mod;
}
int C(int x,int y){
	if(x<y) return 0;
	return jc[x]/(jc[x-y]*jc[y]);
}
int lower(int l,int r,int fnd){
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid]>=fnd) r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	init();
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]) cout<<1<<"\n";
		else cout<<0<<"\n";
		return 0;
	}
	sort(a+1,a+n+1);
	for(int k=3;k<=n;k++){
		int j=a[k];
		int sum=0;
		dp[3][j]=C(k-1,2);
		for(int i=1;i<k;i++){
			for(int l=i+1;l<k;l++){
				if(a[i]+a[l]<=j) sum++;
			}
		}
		dp[3][j]-=sum;
	}
	return 0;
}
