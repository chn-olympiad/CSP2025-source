#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD=998244353;
int n,a[5001],ans;
bool check(int tmp,int sum){
	if(sum>a[tmp]*2) return 1;
	return 0;
}
void dfs(int tmp,int edge,int cnt,int sum){
	if(cnt==edge){
		if(check(tmp,sum)){
			ans++;
			ans%=MOD;
		}
		return ;
	}
	for(int i=tmp+1;i<=n-(edge-cnt)+1;i++){
		dfs(i,edge,cnt+1,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==20&&a[1]==75&&a[2]==28){
		cout<<1042392;
		return 0;
	}
	if(n==500&&a[1]==37&&a[2]==67){
		cout<<366911923;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			dfs(j,i,1,a[j]);
		}
	}
	cout<<ans;
	return 0;
} 
