#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5;
const int mod=998244353;
int n,a[N],c[N],ans;
bool vis[N];
void dfs(int x,int mx,int sum){
	if(x>3){
		if(x>n){
			return;
		}
		if(mx*2<sum){
			ans++;
			ans%=mod;
		}
	}
	for(int i=x+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,max(mx,a[i]),sum+a[i]);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<ans+1;
	return 0;
}
