#include<bits/stdc++.h>
using namespace std;
int n;
long long num=0;
int a[50010];
int dp[1000],used[1000];
bool check(int m){
	long long summ=0;
	for(int i=1;i<=m;i++){
		summ+=a[used[i]];
	}
	if(summ>2*a[used[m]])return 1;
	return 0;
}
void dfs(int k,int m){
	if(k==m){
		if(check(m)){
			num=(num+1)%998244353;
		}
	}
	for(int i=used[k]+1;i<=n;i++){
		if(!dp[i]){
			dp[i]=1;
			used[k+1]=i;
			dfs(k+1,m);
			dp[i]=0;
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
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(0,i);
	}
	cout<<num;
	return 0;
}

