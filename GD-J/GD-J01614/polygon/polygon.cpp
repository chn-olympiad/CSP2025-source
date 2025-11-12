#include<bits/stdc++.h>
using namespace std;
int a[5010];
int b[5010];
bool vis[5010];
int ans1,n;
void dfs(int u,int num){
	if(u==0){
		int maxx=0;
		int num1=0;
		for(int i=1;i<=num;i++){
			maxx=max(maxx,b[i]);
			num1+=b[i];
		}
		if(num1>2*maxx)ans1++;
		ans1%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[u]=a[i];
			dfs(u-1,num);
			vis[i]=0;
			b[u]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++){
		dfs(i,i);
		ans1%=998244353;
		memset(vis,sizeof vis,0);
	}
	cout<<ans1;
	return 0;
}
