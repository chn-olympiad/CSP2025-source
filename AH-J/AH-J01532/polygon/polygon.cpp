#include <bits/stdc++.h>
using namespace std;
int n,a[5010];
int ans[5010],vis[5010],maxn,sum_ans,sum;

void dfs(int now,int step){
	if(now==step+1){
		maxn=0;
		for(int i=1;i<=now-1;i++){
			if(ans[i]>=maxn){
				maxn=ans[i];
			}
		}
		if(sum > (2*maxn)){
			sum_ans+=1;
		}
		return;
	}
	for(int i=1;i<=step;i++){
		if(vis[i]==0){
			vis[i]=1;
			ans[now]=a[i];
			sum+=ans[now];
			dfs(now+1,step);
			vis[i]=0;
			ans[now]=0;
			sum-=ans[now];
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(ans,0,sizeof(ans));
		sum=0;
		dfs(1,3);
	}
	cout<<sum_ans;
	return 0;
}
