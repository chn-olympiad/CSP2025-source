#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=998244353;
int n;
int a[5010];
int ans=0;
int C(int n,int m){
	int sum=1;
	for(int i=n;i>=n-m+1;i--){
		sum*=i;
	}
	for(int i=2;i<=m;i++){
		sum/=i;
	}
	return sum;
}
bool check(int sum,int id){
	if(sum>a[id]*2){
		return 1;
	}
	return 0;
}
void dfs(int sum,int id,int b){
	if(b>=3&&check(sum,id)==1){
		ans++;
	}
	for(int i=id+1;i<=n;i++){
		dfs(sum+a[i],i,b+1);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		ans=0;
		for(int i=3;i<=n;i++){
			ans+=C(n,i);
		}
		cout<<ans%M;
		return 0;
	}
	else{
		dfs(0,0,0);
		cout<<ans%M;
		return 0;
	}
	return 0;
}