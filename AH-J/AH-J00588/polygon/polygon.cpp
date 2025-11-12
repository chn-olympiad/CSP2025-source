#include<bits/stdc++.h>
using namespace std;
long long n,sum,ans,mod=998244353,a[5050],vis[5050];
void dfs(int step,int x,long long cnt){
	if(cnt>a[x]){
		ans++;
		return;
	}
	for(int i=step+1;i<=x-1;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i,x,cnt+a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		dfs(0,i,0);
		ans%=mod;
	}
	
	cout<<ans;
	return 0;
}
