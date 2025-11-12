#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int N=5e3+5;
int n,a[N],vis[N],ans;
void dfs(int sum,int len,int maxn,int start){
	if(sum>=3&&len>2*maxn){
		ans=(ans+1)%MOD;
	}
	for(int i=start+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(sum+1,len+a[i],max(maxn,a[i]),i);
			vis[i]=0;
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
	dfs(0,0,0,0);
	cout<<ans;
	return 0; 
}
