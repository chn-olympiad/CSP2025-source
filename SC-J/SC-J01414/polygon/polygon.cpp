#include<bits/stdc++.h>
using namespace std;
int n,a[5001],cnt,vis_sum[5001],vis_maxai[5001];
void dfs(int s,int sum,int maxai){
	if(s>n){
		if(sum>maxai*2&&(vis_sum[sum]==0||vis_maxai[maxai]==0)){
			cnt=(cnt+1)%998244353;
		}
		return;
	}
	dfs(s+1,sum+a[s],max(maxai,a[s]));
	dfs(s+1,sum,maxai);
}
int main(){
	//记得干掉注释; 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<cnt%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 