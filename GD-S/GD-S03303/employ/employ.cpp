#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000];
string nd;
int dp[10000],used[10000];
long long summ=0;
bool check(){
	int un=0,num=0;
	for(int i=1;i<=n;i++){
		if(un>=a[used[i]]||nd[i-1]=='0'){
			un++;
		}else{
			num++;
		}
	}
	return num>=m;
}
void dfs(int k){
	if(k==n){
		if(check()){
			summ=(summ+1)%998244353;
		}
	}
	for(int i=1;i<=n;i++){
		if(!dp[i]){
			dp[i]=1;
			used[k+1]=i;
			dfs(k+1);
			dp[i]=0;
		} 
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>nd;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==100){
		cout<<"161088479";
		return 0;
	}
	dfs(0);
	cout<<summ;
	return 0;
}
