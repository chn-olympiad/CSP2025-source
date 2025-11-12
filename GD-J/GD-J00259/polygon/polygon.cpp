#include<bits/stdc++.h>
using namespace std;
long long a[50000];
bool vis[6000];
const long long K = 998244353;
long long n;
long long ans = 0;
void dfs(long long sum,long long len,long long maxnumber,int j){
	if(len >= 3){
		if(sum > maxnumber * 2){
			ans++;
			ans %= K;
		}
	}
	if(len > n) return ;
	for(long long i = j + 1;i <= n;i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(sum + a[i],len + 1,max(maxnumber,a[i]),i);
			vis[i] = 0;
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i = 1;i <= n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans % K;
	return 0;
}
