#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int MOD=998244353;
int a[N],n,ans,max_a;
long long c(int x,int y){
	long long v=1;
	for(int i=2;i<=x;i++) v=v*i;
	for(int i=2;i<=y;i++) v/=i;
	for(int i=2;i<=x-y;i++) v/=i;
	return v;
} 
long long c_(int x){
	long long v=0;
	for(int i=0;i<=x;i++) v=(v+c(x,i))%MOD;
	return v;
}
void dfs(int start_,int v_sum,int step,int p){
	if(step>=3 && v_sum>a[start_]){
		ans=(ans+c_(p-1))%MOD;
		return ;
	}
	for(int i=p-1;i>=1;i--){
		dfs(start_,v_sum+a[i],step+1,i);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max_a=max(max_a,a[i]);
	}
	if(max_a==1){
		cout<<c_(n)-1-c(n,1)-c(n,2);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(i,0,1,i);
	}
	cout<<ans%MOD;
	return 0;
} 