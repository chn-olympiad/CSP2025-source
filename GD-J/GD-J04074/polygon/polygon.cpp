#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=998244353;
int n,a[10010],ans;
int vis[5000],s[5000];
void dfs(int num,int len,int h){
	if(len>=3&&a[num]*2<h){
		ans++;
	}
	if(len==n+1) return ;
	for(int i=num+1;i<=n;i++){
		if(!vis[i]){
			s[len]=a[i];
			vis[i]=1;
			dfs(i,len+1,h+a[i]);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans%mod;
	return 0;
}
