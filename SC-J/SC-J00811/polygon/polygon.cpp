#include<bits/stdc++.h>
using namespace std;
int a[5005];
int n;
int ans;

void dfs(int now,int sum,int mx,int cnt){
	if(now>n){
		if(sum>mx*2&&cnt>=3){
			ans++;
			ans %= 998244353;//算不到这...
			return;
		}
		else return;
	}
	dfs(now+1,sum+a[now],max(mx,a[now]),cnt+1);//选(总数+1,和+它,最大值更新)
	dfs(now+1,sum,mx,cnt);//不选(只是跳到下一个,其他均不变)
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}