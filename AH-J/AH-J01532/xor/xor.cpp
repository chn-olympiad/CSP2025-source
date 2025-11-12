#include <bits/stdc++.h>
using namespace std;
const int maxn=5*10e5+15;
long long n,k,a[maxn],vis[maxn],ans[maxn],sum,flag,jk,km;
void dfs(int now){
	if(flag) return;
	if(now==n+1){
		if(sum==k){
			flag=1;
			jk=now-1;
		}
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			ans[now]=a[i];
			sum^=ans[now];
			vis[i]=1;
			if(sum==k){
				flag=1;
				jk=now;
				
			}
			dfs(now+1);
			sum^=ans[now];
			ans[now]=0;
			vis[i]=0;
		}	
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(vis,0,sizeof(vis));
	dfs(1);
	
	cout<<jk;
	
	
	return 0;
}
