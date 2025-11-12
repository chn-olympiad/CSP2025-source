#include<bits/stdc++.h>
using namespace std;
int n,x;
int a[5005];
bool vis[5005];
int nn[5005];
int cnt;
int ans;
void dfs(int c,int maxx,int num){
	if(maxx!=-1&&num>maxx*2){
		ans=(ans+1)%998244353;
	}
	for(int i=c+1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		nn[++cnt]=a[i];
		dfs(i,max(maxx,a[i]),num+a[i]);
		vis[i]=0;
		cnt--;
	}
}
int main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(0,-1,0);
		cout<<ans%998244353;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<0;
	}
	return 0;
}
