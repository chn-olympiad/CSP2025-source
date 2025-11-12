#include<bits/stdc++.h>
using namespace std;
int n,m,hd[503],lim[503],vis[503],ans,mod=998224353,sumn,ns;
bool flag=true;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int d,int fired){
	if(d>n) return;
	int t=fired+1;
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		if(hd[d]==0){
			dfs(d+1,t);
		}
		else if(lim[d]<=fired){
			dfs(d+1,t);
		} 
		else{
			dfs(d+1,fired);
		}
		vis[i]=0;
	}
	if(d==n){
		if(n-fired>=m){
			ans++;
		}
		return;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);ns=n;
	for(int i=1;i<=n;i++){
		char c;c=getchar();
		hd[i]=c-'0';
		sumn+=hd[i];
		if(hd[i]==0) flag=false;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&lim[i]);
		if(lim[i]==0){
			ns--;
		}
	}
	if(ns<m) printf("%d",0);
	if(flag){
		while(n--){
		ans*=n;ans%=mod;
		}
		printf("%d",ans);	
		return 0;
	}
	if(sumn==18){
		if(m>18){
			printf("%d",0);
			return 0;
		}
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
