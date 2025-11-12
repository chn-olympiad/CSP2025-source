/*xg333 CSP-J must win!!!
T3代码*/
/*
xg333:我的思路是这样的：xor有一个重复还原性，例：
1000110001 xor 1001011011 = 0001101010
0001101010 xor 1001011011 = 1000110001
所以：我们可以用前缀合！
sum[i]表示从a[1]到a[i]的异或合
这可以大大地减少我们的复杂度
但，还是不够
我在想：我现在是知道一个L，需要快速找到与之对应的R
两个问题：
1.你怎么保证你这个是最优方案？比如你选的区间内有两个等价的区间呢？已解决
2.你怎么快速去找？（有就是满的，没有就是60)
猜测时间复杂度O(nlogn)
有个小优化：如果有=k的，就单独算一个区间
猜测算法:一维dp
若a[i]=k
dp[i]=1;
dp[i]代表从1~i,最大区间个数
dp[i]=max(dp[i],dp[i-1])
dp[i+(从i能找到的最近的区间)]=max(dp[i+(从i能找到的最近的区间)],dp[i]+1)
*/
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define endl '\n'
int sum[500001];
int a[500001];
int dp[500001];
int n,m;
int find_id(int x){
	for(int i=x;i<=n;i++){
		if(a[i]==m) return -1;
		if((sum[i]^sum[x-1])==m) return i;
	}
	return -1;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		
		dp[i]=max(dp[i-1],dp[i]);
		if(a[i]==m){
			dp[i]++;
		}
		else if(find_id(i)!=-1){
			if(a[find_id(i)]!=m) dp[find_id(i)]=max(dp[find_id(i)],dp[i]+1);
		}
	}
	cout<<dp[n];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}