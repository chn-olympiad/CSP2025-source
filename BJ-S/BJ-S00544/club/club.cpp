/*
17:01
*/
#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][5],f[100010];
int dfs(int x,int p1,int p2,int p3){
	int ret=-1e9;
	if(x==0){
		return 0;
	}
	if(p1<n/2){
		ret=max(ret,dfs(x-1,p1+1,p2,p3)+a[x][1]);
		// printf("%d %d\n",x,ret);
	}
	if(p2<n/2){
		ret=max(ret,dfs(x-1,p1,p2+1,p3)+a[x][2]);
		// printf("%d %d\n",x,ret);
	}
	if(p3<n/2){
		ret=max(ret,dfs(x-1,p1,p2,p3+1)+a[x][3]);
		// printf("%d %d\n",x,ret);
	}
	return ret;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",a[i]+1,a[i]+2,a[i]+3);
		printf("%d\n",dfs(n+1,0,0,0));
	}
	return 0;
}