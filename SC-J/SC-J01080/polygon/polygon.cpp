#include<bits/stdc++.h>
using namespace std;

const int N=5005,M=1e4+5,Mod=998244353;
int a[N],dp[M][4],lst[M][4];

inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*f;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);lst[0][0]=1;
	int maxn=a[n]*2+1,ans=0,j;
	for(int i=1;i<=n;i++){
		for(j=a[i];j<maxn;j++){//数值还没有超过maxn 
			dp[j][1]=lst[j-a[i]][0];
			dp[j][2]=lst[j-a[i]][1];
			dp[j][3]=(lst[j-a[i]][2]+lst[j-a[i]][3])%Mod;
		}
		dp[maxn][1]=dp[maxn][2]=dp[maxn][3]=0;
		for(j=maxn-a[i];j<=maxn;j++){//去凑maxn 
			dp[maxn][1]=(dp[maxn][1]+lst[j][0])%Mod;
			dp[maxn][2]=(dp[maxn][2]+lst[j][1])%Mod;
			dp[maxn][3]=(dp[maxn][3]+lst[j][2]+lst[j][3])%Mod; 
		}
		for(j=a[i];j<=maxn;j++){
			lst[j][1]=(lst[j][1]+dp[j][1])%Mod; 
			lst[j][2]=(lst[j][2]+dp[j][2])%Mod; 
			lst[j][3]=(lst[j][3]+dp[j][3])%Mod; 
		}
		for(j=a[i]*2+1;j<=maxn;j++) ans=(ans+dp[j][3])%Mod;
	}
	cout<<ans;
	return 0;
}
/*
有一个显然的思路：定义dp[i][num1][num2]代表处理到第i项，最大值为num1，和为num2的方案数
num2>num1后，直接用0代替
奈何这样是O(n a^2)的，只有80pts

我好像可以给a数组排序，这样最大值就是对应的a[i]了 
那么有：定义dp[i][num]代表当前处理到i(必须选择i)，和为num(超过2*maxa后存储为2*maxa+1)的方案数
但是我这样好像无法处理选择数量不足3
那就再加一个维度吧，0/1/2/3，代表没选过/1个/2个/3个及以上

看起来我AK了？ 
*/