//T3 普及+/提高
/*
1.对于任意区间[i,j](1<=i<=j<=n)，答案可以确定， 
并且不会被任意[i,j]外区间影响，可记忆化。
考虑使用动规。
f[l][r]:区间[l,r]最优值
ans:max{f[l][k-1]+f[k][r]}(2<=k<=n)
转移：max{f[l][k-1]+f[k][r],(lr区间能否值为k?)}(2<=k<=n)
初始化：f[i][i]=(a[i]等于k?)
如何计算lr区间值为k:前缀和
时间复杂度:O(n^2) 微微小于n^2
可夺60分！ 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e3+3;
int n,K,a[N],qzh[N],f[N][N],ans=-1;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> K;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		qzh[i] = a[i]^qzh[i-1];
		f[i][i] = (a[i]==K);
	}for(int len=2;len<=n;++len){
		for(int l=1;l+len-1<=n;++l){
			int r = l+len-1;
			for(int k=2;k<=n;++k){
				f[l][r]=max(f[l][r],max(f[l][k-1]+f[k][r],(int)((qzh[r]^qzh[l-1])==K)));
			}
		}
	}for(int k=2;k<=n;++k){
		ans = max(ans,f[1][k-1]+f[k][n]);
	}cout << ans; 
	return 0;
}
