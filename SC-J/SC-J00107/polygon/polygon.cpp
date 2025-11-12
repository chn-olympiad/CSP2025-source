#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3+3,MOD=998244353;
int n;
int a[MAXN];
long long ans,power[MAXN];
void dfs(int step,int sum,int k){
	if(sum>k){
//		printf("[%d,%d]",step,sum);
		ans=(ans+power[step])%MOD;
		return ;
	}
	if(step==0) return ;
	dfs(step-1,sum+a[step],k);
	dfs(step-1,sum,k);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	power[0]=1;
	for(int i=1;i<=n;i++) power[i]=power[i-1]*2%MOD;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag){
		ans=(power[n]-n-n*(n-1)/2-1)%MOD;
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(i-1,0,a[i]);
//		printf("%d %d\n",i,ans);
	}
//	cout<<"\n";
	cout<<ans;
	return 0; 
}
/*
题意转化：
在一个序列中选出若干个数组成集合 S，
使得 sum{s} > 2*max{s}

思路1-  24pts-40pts： 
讨论但 ai 作为 max{s} 时对于答案的贡献，
先给序列排序，在选了至少一个 j > i时 ，显然 max 值就变成了 aj 舍去 
当选的全是 j<i 时 ,用dfs暴力求解 (加一点剪枝） 

思路2 根据数据点猜测 O(n^2) 比较合理，O(n^2logn) 比较极限  
根据思路1，外层循环 O(n),j>i O(1)求，j<i O(2^n) 
时间阈值在 j<i，能否把这个地方优化成 O(n) 
*/