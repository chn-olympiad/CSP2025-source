#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
const int mod=998244353;
void dfs(int x,int sum,int mx,int t){
	if(x>n){
		if(t<=2) return ;
		if(sum>mx*2) {
			ans++;
			ans%=mod;
			return ;
		}
		return ;
	}
	dfs(x+1,sum,mx,t);
	dfs(x+1,sum+a[x],max(mx,a[x]),t+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
