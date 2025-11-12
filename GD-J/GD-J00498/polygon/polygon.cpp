#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005];
bool vis[5005];
long long ans;
void dfs(int m,long long sum){
	if(m>=3){
		int maxa=a[b[m]];
		if(sum>2*maxa){
			ans++;
		}
	}
	for(int i=b[m]+1;i<=n;i++){
		if(!vis[i]){ 
			b[m+1]=i;
			vis[i]=true;
			dfs(m+1,sum+a[i]);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0);
	cout<<ans%998244353<<endl;
	return 0;
}
