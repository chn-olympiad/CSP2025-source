#include<bits/stdc++.h>
using namespace std;
int n,m,flag[505],vis[505];
int dif[505],c[505],ans;
const int mod=998244353;
void dfs(int now,int sum,int noc){
	if(now==n+1){
		if(sum>=m) ++ans,ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==0){
			flag[i]=1;
			vis[now]=i;
			if(c[i]>noc){
				if(dif[now]==0)
					dfs(now+1,sum,noc+1);
				else
					dfs(now+1,sum+1,noc); 
			}
			else dfs(now+1,sum,noc+1);
			vis[now]=0;
			flag[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		dif[i]=int(ch-'0');
	}
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs(1,0,0);
	printf("%d",ans%mod);
	return 0;
}
