#include<bits/stdc++.h>
using namespace std;

/*
暴力：选或不选（O(2^n)）（40分）+ 全为1的情况（24分） = 64分
0-1背包
每个物品（小木棍）选或不选，记录其中最大值
dp[i]：选前i个小木棍（滚动数组）（O(n*n)）
*/

const int MAXN=5010,mod=998244353;
long long n,ans;
int a[MAXN];

void dfs(int now,int cnt,int sum,int maxn){
	if(now>n){
		if(cnt>=3&&sum>(maxn<<1)) (ans+=1)%=mod;
		return ;
	}
	dfs(now+1,cnt,sum,maxn);
	dfs(now+1,cnt+1,sum+a[now],max(maxn,a[now]));
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	int maxn=0;
	for(int i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]);
	
	if(n<=23){
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	if(maxn<=1&&n>20){
		long long sum=1;
		ans+=sum;
		int cnt=1;
		for(int i=n-1;i>=3;i--){
			sum=(sum*(i+1)/cnt);
			ans=(ans+sum)%mod;
			cnt++;
		}
		cout<<ans<<endl;
	}
	return 0;
}