#include<bits/stdc++.h>
using namespace std;
int n,a[5050],ans;
bool vis[5050];
void dfs(int s,int maxn,int total,int num){
	if(num>=3&&total>2*maxn){
		ans++;
		return ;
	}
	for(int i=s;i<=n;++i){
		if(vis[i]==0){
			vis[i]=1;
			if(maxn>a[i])
			dfs(s+1,maxn,total+a[i],num+1);
			else 
			dfs(s+1,a[i],total+a[i],num+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
	}	
	dfs(1,0,0,0);
	printf("%d",ans);
}
