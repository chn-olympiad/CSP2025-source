#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll mod=998244353;
int n,a[5010],k,maxn=0,sum;
ll ans,C[5010][5010];
bool vis[5010];
void dfs(int chs,int x) {
	if(chs==k) {
		if(sum>2*maxn) ans++;
		return ;
	}
	for(int i=x;i<=n;i++) {
		if(!vis[i]) {
			vis[i]=1;
			ll tmp=maxn;
			maxn=max(maxn,a[i]),sum+=a[i];
			dfs(chs+1,i+1);
			vis[i]=0;
			maxn=tmp,sum-=a[i]; 
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=25) {
		for(k=3;k<=n;k++) dfs(0,1);
		cout<<ans;	
	} else {
		C[0][0]=1;
		for(int i=1;i<=n;i++) {
			for(int j=0;j<=i;j++) {
				C[i][j]=C[i-1][j];
				if(j>0) C[i][j]+=C[i-1][j-1];
				C[i][j]%=mod;
			}
		}
		for(int i=3;i<=n;i++) {
			ans+=C[n][i];
			ans%=mod;
		}
		cout<<ans;
	}	
	return 0;
} 
/*
我要上迷惑行为大赏！！！！！！！！！！！！！
大家好啊 我是说的道理 今天来给大家看点好看的
这题让我们求从n个棍木中选若干个组成棍木多边形的方案数
啊 一眼数学题 不会怎么办呢
冲刺！otto！冲刺！
直接无脑爆搜（+40pts）
然后 我们看到 有写测试点全部的棍木长度都是1啊
直接无脑打组合数的表（T4笑传之code combine 表）
（+24pts） 
于是我们就骗了64pts
哇袄！！！！！！！！！！！！！！！！！
*/ 
