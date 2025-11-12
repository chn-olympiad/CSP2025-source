#include<bits/stdc++.h>
using namespace std;
int a[505],vis[505],n,m;
long long ans=0;
char c[505];
void dfs(int x,int k){
	if(k==n){
		if(n-x>=m)ans++;
		return;
	}for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			int kk=x;
			if(kk>=a[i]||c[k+1]=='0')kk++;
			dfs(kk,k+1);
			vis[i]=0;
		}
	}return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0);
	cout<<ans;
	return 0;
} 
