#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n,ans;
int a[5050];
void dfs(int id,int maxx,int sum,int num){
	for(int i=id+1;i<=n;i++){
		dfs(i,max(maxx,a[i]),sum+a[i],num+1);
	}
	if(sum>(maxx*2)&&num>=3){
		ans++;
		ans%=MOD;
		return;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
} 