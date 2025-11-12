#include<iostream>
#include<queue>
using namespace std;
const int mod=998244353;
int n,ans;
int a[5010];
void dfs(int sum,int maxn,int cnt){
	if(sum>maxn*2&&cnt>=3){
		ans++;
		ans%=mod;
	}
	for(int i=cnt;i<n;i++){
		dfs(sum+a[i],max(maxn,a[i]),++cnt);
	}
	return ;
}
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
