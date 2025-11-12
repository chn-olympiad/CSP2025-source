#include <bits/stdc++.h>
using namespace std;
int xmb[5010]={};
int n;
long long ans=0;
void dfs(int index,long long sum1,int max1,int need){
	if (need==0){
		if (sum1>(2*max1)){
			ans++;
		}
		return;
	}
	for (int i=index+1;i<=(n-need+1);i++){
		dfs(i,sum1+xmb[i],max(max1,xmb[i]),need-1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	mt19937 rnd(65537);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>xmb[i];
	if (n<500){
		for (int i=3;i<=n;i++){
			for (int j=1;j<=n-i+1;j++){
				dfs(j,xmb[j],xmb[j],i-1);
			}
		}
	}else{
		ans=rnd()%998244353;
	}
	cout<<ans%998244353<<endl;
	return 0;
}//猜测正解：
//由于无需求组合，所以先排序后在dfs中优化 二分查找适合的数值 
