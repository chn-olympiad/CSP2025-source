#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0, f=1;
    char ch=getchar();
    for(ch;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
    for(ch;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}
constexpr int INF=1e9, N=5005, MOD=998244353;
int n, a[N], f[N*N], g[N*N], tot, ans;
/*
问题:
给出 n 个元素的序列 a, 要求从其中选择出一些元素, 使得它们的和大于最大值的两倍, 求方案数


设 f[j] 表示前 i 个元素, 和为 j 的方案数
设 g[j] 表示没有限制, 前 i 个元素组成 j 的方案数 
转移:
因为选出的和 j 要 > a[i]*2, 所以枚举 tot~a[i]*2+1
枚举 tot>=k>a[i]*2, f[j]+=g[j-a[i]] 

至此正确性已有保证, 现预计 80pts
如何处理 5000 这种值域很大的情况? 
一个背包有没有优化的可能?
背包注定有 n*W 的复杂度, 也许要换一种 dp 方式
序列 dp?
 
*/
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(), tot+=a[i];
	sort(a+1, a+1+n);
	g[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=tot;j>2*a[i];j--)
			f[j]=(f[j]+g[j-a[i]])%MOD;
		for(int j=tot;j>=a[i];j--)
			g[j]=(g[j]+g[j-a[i]])%MOD;
	}
	for(int i=1;i<=tot;i++) ans=(ans+f[i])%MOD;
	cout<<ans;
	return 0;
}
