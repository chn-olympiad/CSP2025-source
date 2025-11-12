#include <bits/stdc++.h>
using namespace std;

const int mod=998224353;
const int maxn=5010;
int nums[maxn],pref[maxn],dp[maxn][maxn];
int n,ans;

void open(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}
//void init(){
//	fn[0]=1;
//	for(int i=1;i<=5000;i++){
//		fn[i]=((long long)fn[i-1]*2)%mod;
//	}
//}
void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&nums[i]);
	}
}
int numof1(int num){int cnt=0;while(num){if(num&1){cnt++;}num>>=1;}return cnt;}
void solve1(){
	for(long long i=0;i<(1ll<<n);i++){
		if(numof1(i)<3)continue;
		int mx=0,sumn=0;
		for(int j=1;j<=n;j++){
			if(i&(1ll<<(j-1))){
				mx=max(mx,nums[j]);
				sumn+=nums[j];
			}
		}
		if(sumn>mx*2)ans=(ans+1)%mod;
	}
}
int dfs(int dep,int mx,int sum,bool fg){
	if(!fg && sum<2*mx)return 0;
	if(dep==n+1)return 1;
	int cnt=0;
	if(!fg)cnt=(cnt+dfs(dep+1,mx,sum,0))%mod;
	cnt=(cnt+dfs(dep+1,nums[dep],sum+nums[dep],0))%mod;
	return cnt;
}
void solve2(){
	sort(nums+1,nums+n+1);
	for(int i=1;i<=n;i++){
		ans=(ans+dfs(i,0,0,1))%mod;
	}
}
void output(){
	printf("%d",ans);
}
int main(){
	open();
	input();
	solve1();
	output();
	close();
	return 0;
}

